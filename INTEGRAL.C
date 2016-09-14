#include <math.h>




int simpson(double a,double b,double e,double (*g)(double *),double *s, double *gArgs, int Index)//Вычисление определенного интеграла методом Симпсона
																							//a - нижняя граница интегрирования
                                                                     //b - верхняя граница интегрирования
                                                                     //e - требуемая погрешность вычислений
                                                                     //g - указатель на интегрируемую функцию
                                                                     //s - указатель на результат интегрирования
                                                                     //gArgs - массив аргументов интегрируемой функци
                                                                     //Index - индекс аргумента интегрируемой функции в массиве gArgs по которому ведется интегрирование
                                                                     //Возвращает 0 при удачном интегрировании,
                                                                     //1 - если не удалось достигнуть требуемой точности.
{
	int n=20,nmax=200000,i;
   double h,s0,g_a,g_b,s1=0,g0;

   h=(b-a)/n;
   gArgs[Index]=b;
   g_b=g(gArgs);
   gArgs[Index]=a;
   g_a=g(gArgs);

   for(i=1,*s=0;i<n-1;i++)
   {
   	gArgs[Index]+=h;
      g0=g(gArgs);
      s1+=2.*g0;
      *s+=4.*g0;
      i++;
      gArgs[Index]+=h;
      g0=2.*g(gArgs);
      s1+=g0;
      *s+=g0;
   }
   gArgs[Index]+=h;
   g0=g(gArgs);
   s1+=2.*g0;
   *s+=4.*g0;
   *s+=g_a;
   *s+=g_b;
   *s*=h/3.;
	do
   {
   	s0=*s;
      n*=2;
      h/=2.;
      gArgs[Index]=a;
		for(i=1,*s=s1;i<n-1;i++)
   	{
   		gArgs[Index]+=h;
         g0=g(gArgs);
   		s1+=2.*g0;
   		*s+=4.*g0;
      	i++;
      	gArgs[Index]+=h;
   	}
   	gArgs[Index]+=h;
      g0=g(gArgs);
   	s1+=2.*g0;
   	*s+=4.*g0;
   	*s+=g_a;
   	*s+=g_b;
      *s*=h/3.;
		if(fabs(*s-s0)<e)
      	return 0;
	} while(n<nmax);
	// аварийный выход
	return 1;
}
