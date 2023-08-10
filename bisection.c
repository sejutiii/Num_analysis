#include<stdio.h>
#include<math.h>

#define f(x) ((x)*(x)*(x) + 4*(x)*(x)-5)
#define EPS 10.0e-6

void bisection(double a, double b)
{
    if(f(a)*f(b) > 0)
    {
        printf("No root\n");
        return;
    }

  
    double c= (a+b)/2;
   // printf("%d %lf %lf %lf %lf %lf %lf\n", i, a, b,c, f(a), f(b), f(c));

    if(fabs(f(c)) < EPS)
    {
        printf("ROOT= %lf\n", c);
        return;
    }

    else if((f(a) * f(c)) < 0)
    {
        bisection(a, c);
    }
    else bisection (b, c);
    
}

int main()
{
	double a= -5, b=5, interval;
	int n=6;
	
	interval= (b-a)/n;
	for(int i=0; i<n; i++)
	{
		b= a+ interval;
		bisection(a, b);
		//a += interval;
		a= b;
	}
	return 0;
}






