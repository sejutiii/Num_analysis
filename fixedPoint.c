#include<stdio.h>
#include<math.h>

#define f(x) ((x)*(x)*(x) + 4*(x)*(x)-10.0)
#define EPS 10.0e-6

double func(double x)
{
    return sqrt((10- (x*x*x))/4);
}

void fixedPoint(double x, int i)
{
    double x1 = func(x);

    printf("%d %lf %lf %lf \n", i, x, x1, f(x));

    if(fabs(f(x1)) < EPS)
    {
        printf("Root= %lf\n", x1);
        return;
    }

    fixedPoint(x1, i+1);
}

int main()
{
    double x = 1.5;
    printf("Iter \t x \t x1 \t f(x)");
    fixedPoint(x, 1);
    return 0;
}