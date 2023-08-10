#include<stdio.h>
#define f(x) ((x*x) +1)

int main()
{
	double a= 0.0, b= 2.0;
	
	int N= 10;
	double h= (b-a)/N;
	
	double x[11]= {0.0, 0.2, 0.4, 0.6, 0.8, 1.0, 1.2, 1.4, 1.6, 1.8, 2.0};
	
	double y[11]= {1.0, 1.04, 1.16, 1.36, 1.64, 2.0, 2.44, 2.96, 3.56, 4.24, 5.0};
	
	double sum_X= y[0] + y[N];
	
	double sum_I= 0;
	
	for(int i=1; i<N; i++)
	{
		sum_I= sum_I + y[i];
	}
	
	double I= h * (sum_X + (2* sum_I))/ 2;
	
	printf("Trapezoidal Rule -----------------\n");
	printf("Integral value= %lf\n", I);
	printf("----------------------------------\n");
}
