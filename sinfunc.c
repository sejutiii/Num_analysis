#include<stdio.h>
#include<math.h>


int main()
{
	int n=100;
	double a=0, b= 2*M_PI;
	double h= (b-a)/n;
	
	double x=a;
	
	printf("\"x\",\"sin(x)\"\n");
	printf("%lf, %lf\n", x, sin(x)); // terminal -> man sin = manual for sin
	
	for(int i=1; i<n; i++)
	{
		x=x+h;
		printf("%lf,%lf\n", x, sin(x)); // gcc sinfunc.c -lm
	}
	
	x=b;
	printf("%lf, %lf\n", x, sin(x));
	return 0;
}

// rw= read write = source file
// rwx= read write execute = object file
