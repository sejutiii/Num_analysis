#include<stdio.h>
#include<math.h>

#define f(x) (sqrt(x))
#define g(x) (x*x)
#define h(x) (g(x)- f(x))

#define EPS 10.0e-6


double bisection(double a, double b)
{
   /* if(f(a)*f(b) > 0)
    {
        printf("No root\n");
        return;
    } */

    double c= (a+b)/2;
   // printf("%d %lf %lf %lf %lf %lf %lf\n", i, a, b,c, f(a), f(b), f(c));

    if(fabs(h(c)) < EPS)
    {
        return c;
    }

    else if((h(a) * h(c)) < 0)
    {
        bisection(a, c);
    }
    else bisection (b, c);
    
}

double trapz(double a, double b, int N)
{
	double h= (b-a)/N;
	
	double x[N+1], y[N+1];
	
	x[0]= a;
	
	for( int i=1; i<N; i++)
	{
		x[i]= x[i-1] + h;
	}
	
	x[N] = b;
	
	for(int i=0; i<=N; i++)
	{
		y[i]= fabs(h(x[i]));
	}
	
	double sum_X= y[0] + y[N];
	
	double sum_I= 0;
	
	for(int i=1; i<N; i++)
	{
		sum_I= sum_I + y[i];
	}
	
	double I= h * (sum_X + (2* sum_I))/ 2;
	
	return I;
}

int main()
{
	double a= 0.0;
	double b= bisection(0.5, 1.25);
	
	int N= 10;
	
	double I= trapz(a, b, N);
	I= fabs(I);
	
	printf("Area = %lf\n", I); 
}














