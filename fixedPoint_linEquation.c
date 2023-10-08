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

//double x_initial[3]= {0, 0, 0}, x[3];

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

void initialize()
{
    
}