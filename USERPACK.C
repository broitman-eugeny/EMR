#include "d:\work\bc\include\mcadincl.h"
    
    extern FUNCTIONINFO FPPE_Krug_ap,FSechen_Hor_Plosk;

    
    char *ErrorMessageTable[] = {
    "argument must be real",    //  error 1 --  argument must be real
    "insufficient memory",      //  error 2 --  memory allocation error
    "interrupted",              //  error 3 --  execution interrupted
    "Psi_0<=0 || Psi_0>=180",   //  error 4 --  параметр пси_0 вышел из области определения
    "Не сходится интеграл"      //  error 5 --  Не сходится интеграл Френеля или гамма
    };


BOOL WINAPI DllEntryPoint (HANDLE hDLL, DWORD dwReason, LPVOID lpReserved)
{
  switch (dwReason)
  {
    case DLL_PROCESS_ATTACH:
    {

      // DLL is attaching to the address space of the current process.
      //
		  if (!CreateUserErrorMessageTable( hDLL, 5, ErrorMessageTable ) )
				break;

 		  if ( CreateUserFunction( hDLL, &FPPE_Krug_ap) == NULL )
 				break;

        if ( CreateUserFunction( hDLL, &FSechen_Hor_Plosk) == NULL )
 				break;

        

    }

	 case DLL_THREAD_ATTACH:        // A new thread is being created in the current process.
	 case DLL_THREAD_DETACH:        // A thread is exiting cleanly.
	 case DLL_PROCESS_DETACH:      // The calling process is detaching the DLL from its address space.

		break;
  }
  return TRUE;
}



