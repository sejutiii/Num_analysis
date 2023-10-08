#include<stdio.h>
#include<math.h> 
#include<stdlib.h>
#include<stdbool.h>
#define EPS 0.0001;
#define n 3

double augMat[n][n+1]= {
    {20, 1, -2, 17},
    {3, 20, -1, -18},
    {2, -3, 20, 25}
};

double x_initial[3]= {0, 0, 0}, x[3];

bool isDominant()
{
    for(int i=0; i<n; i++)
    {
        double sum=0;
        for(int j=0; j<n; j++)
        {
            if(i != j)
            {
                sum += fabs(augMat[i][j]);
            }
        }

        if(fabs(augMat[i][i]> sum))
            return true;
        else return false;
    }
}

void jacobian()
{
    int j=0;
    bool flag= true;
    while(flag)
    {
        x[0]= (augMat[0][3] - (augMat[0][1]*x_initial[1] + augMat[0][2]*x_initial[2]))/ augMat[0][0];
        x[1]= (augMat[1][3] - (augMat[1][0]*x_initial[0] + augMat[1][2]*x_initial[2]))/ augMat[1][1];
        x[2]= (augMat[2][3] - (augMat[2][0]*x_initial[0] + augMat[2][1]*x_initial[1]))/ augMat[2][2];

        if((fabs(x[0]-x_initial[0]) < 0.0001) && (fabs(x[1]-x_initial[1]) < 0.0001) && (fabs(x[2]-x_initial[2]) < 0.0001))
        {
            flag = false;
            break;
        }

        for(int i=0; i<n; i++)
        {
            x_initial[i]= x[i];
        }

        printf("iter= %d\n", j);
        for(int i=0; i<n; i++)
        {
            printf("%lf ", x[i]);
        }
        printf("\n");

        j++;
    }

     

}

int main()
{
    if(isDominant())
        jacobian();
}