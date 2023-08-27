#include<stdio.h>
#include<math.h> 
#define EPS 0.1e2
#define n 4

double AugmentedMat[n][n+1]= {
    {1, -1, 2, -1, -8},
    {2, -2, 3, -3, -20},
    {1, 1, 1, 0, -2},
    {1, -1, 4, 3, 4}
};

void printMatrix()
{
    printf("The output matrix is:\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n+1; j++)
        {
            printf("%.2lf\t", AugmentedMat[i][j]);
        }
        printf("\n");
    }
}

void equationSolving()
{
    double m, pivot;
    for(int p=0; p<n; p++)
    {
        if(fabs(AugmentedMat[p][p]) < EPS)
        {
            for(int j=p+1; j<n; j++)
            {
                 if(fabs(AugmentedMat[j][p]) < EPS)
                 {
                    for(int k=p; k<n+1; k++)
                    {
                        double temp= AugmentedMat[p][k];
                        AugmentedMat[p][k]= AugmentedMat[j][k];
                        AugmentedMat[j][k]= temp;
                    }
                    break;
                 }
            }
        }

        for(int j=0; j<n; j++)
        {
            if(p == j) continue;
            m= AugmentedMat[j][p]/ AugmentedMat[p][p];

            for(int k=0; k<n+1; k++)
            {
                AugmentedMat[j][k]= AugmentedMat[j][k]- m*AugmentedMat[p][k];
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        pivot = AugmentedMat[i][i];
        for(int j=0; j<n+1; j++)
        {
            AugmentedMat[i][j] = AugmentedMat[i][j]/ pivot;
        }
    }
}


int main()
{
    equationSolving();
    printMatrix();
}
