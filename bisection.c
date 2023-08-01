#include<stdio.h>
#include<math.h>

double func(double x)
{
    return (x*x)- (5*x);
}

double findRoot(double a, double b)
{
    double fa= func(a);
    double fb= func(b);

    if(!(fa*fb) < 0)
    {
        printf("Root doesn't exist\n");
        return 0;
    }

    else
    {
        c= (a+b)/2;
        double fc= func(c);
        if(fc == 0)
        {
            printf("Root = %d", c);
            return 0;
        }
        else if(fa*fb <0)
        {
            b=c;
        }
        else a=c;
        goto label;
    }
}

int main()
{
    double a,b,c;
    printf("Enter the bounds: ");
    scanf("%d %d", &a, &b);
    
    return 0;
}

