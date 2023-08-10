#include<stdio.h>
#include<math.h>

#define f(x) (sin(x))

double x[101], y[101], dy[101];

int main()
{
	int n=100;
	double a=0, b= 2*M_PI;
	double h= (b-a)/n;
	
	x[0]=a;
	y[0]= f(x[0]);
	
	for(int i=1; i<n; i++)
	{
		x[i]= x[i-1]+h;
		y[i]= f(x[i]);
	}
	
	x[n]=b;
	y[n]= f(x[n]);
	
	dy[0]= (y[1]- y[0])/(x[1]-x[0]);
	
	for(int i=1; i<n; i++)
	{
		dy[i]= (y[i+1]-y[i-1])/(x[i+1]- x[i-1]);
	}
	
	dy[n]= (y[n]-y[n-1])/(x[n]- x[n-1]);
	
	printf("\"x\",\"f(x)\",\"f'(x)\"\n");
	
	for(int i=0; i<n; i++)
	{
		printf("%lf,%lf,%lf\n", x[i], y[i], dy[i]);
	}
	return 0;
}
