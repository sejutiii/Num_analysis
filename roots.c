#include<stdio.h>
#include<math.h>

#define f(x) ((x)*(x)*(x) + 4*(x)*(x)-10.0)
#define EPS 10.0e-6

void bisection(double a, double b, int i);

void falsePosition(double a, double b, int i);

void secant(double a, double b, int i);

int main()
{
    int i, n=100;
    double a=1.25, b=1.5, c;

    printf("Iter\ta\tb\tc\tf(a)\tf(b)\tf(c)\n");

    // bisection(a,b, 1);

    // falsePosition(a,b,1);

    secant(a,b,1);

    return 0;
}

void bisection(double a, double b, int i)
{
    if(f(a)*f(b) > 0)
    {
        printf("No root\n");
        return;
    }

  
    double c= (a+b)/2;
    printf("%d %lf %lf %lf %lf %lf %lf\n", i, a, b,c, f(a), f(b), f(c));

    if(fabs(f(c)) < EPS)
    {
        printf("ROOT BS = %lf\n", c);
        return;
    }

    else if((f(a) * f(c)) < 0)
    {
        bisection(a, c, i+1);
    }
    else bisection (b, c, i+1);
    
}

void falsePosition(double a, double b, int i)
{
    if(f(a)*f(b) > 0)
    {
        printf("No root\n");
        return;
    }

  
    double c= (b-((f(b)*(b-a))/(f(b)-f(a))));
    printf("%d %lf %lf %lf %lf %lf %lf\n", i, a, b,c, f(a), f(b), f(c));

    if(fabs(f(c)) < EPS)
    {
        printf("ROOT BS = %lf\n", c);
        return;
    }

    else if((f(a) * f(c)) < 0)
    {
        falsePosition(a, c, i+1);
    }
    else falsePosition(b, c, i+1);
    
}

void secant(double a, double b, int i)
{
    double c= (b-((f(b)*(b-a))/(f(b)-f(a))));
    printf("%d %lf %lf %lf %lf %lf %lf\n", i, a, b,c, f(a), f(b), f(c));


    if(fabs(f(c)) < EPS)
    {
        printf("ROOT BS = %lf\n", c);
        return;
    }

    a=b;
    b=c;

    secant(a,b,i+1);
}