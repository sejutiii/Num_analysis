#include<stdio.h>
#define f(x) ((x*x) +1)

int main()
{
	double a= 0.0, b= 2.0;
	
	int N= 10;
	
	if(N%2 != 0) N= N+1;
	
	double h= (b-a)/N;
	
	double x[11], y[11];
	
	x[0]= a;
	
	for( int i=1; i<N; i++)
	{
		x[i]= x[i-1] + h;
	}
	
	x[N] = b;
	
	for(int i=0; i<=N; i++)
	{
		y[i]= f(x[i]);
	}
	
	double sum_X= y[0] + y[N];
	
	double sum_O= 0, sum_E= 0;
	
	for(int i=1; i<N; i++)
	{
		if( i%2 ==0)
		sum_E = sum_E + y[i];
		
		else sum_O = sum_O + y[i];
	}
	
	double I= h * (sum_X + (4* sum_O) + (2*sum_E)) / 3;
	
	printf("Simpson's 1/3 Rule ---------------\n");
	printf("Integral value= %lf\n", I);
	printf("----------------------------------\n");
}
