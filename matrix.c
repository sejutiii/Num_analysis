#include<stdio.h>
#include<math.h> 
#include<stdlib.h>
#define EPS 10e-9
#define n 3

double augMat[n][n+1]= {
    {4, -1, 1, 8},
    {2, 5, 2, 3},
    {1, 2, 4, 1}
};

double inverse[n][n]= {
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1}
};

double determinant()
{
    double det=1;
    for(int i=0; i<n; i++)
    {
        det = (det*augMat[i][i]);
    }
    return det;
}

void printMatrix()
{
    printf("The output matrix is:\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n+1; j++)
        {
            printf("%.2lf\t", augMat[i][j]);
        }
        printf("\n");
    }

    printf("Inverse Matrix- \n");

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%.2lf\t", inverse[i][j]);
        }
        printf("\n");
    }
}

void solveTheProblem()
{
    for(int i=0; i<n; i++)
    {
        int temp=-1;
        double pivot= augMat[i][i];

        if(fabs(pivot) < EPS)
        {
            for(int j= i+1; j<n; j++)
            {
                if(augMat[j][i] !=0)
                {
                    temp= j;
                    break;
                }
            }

            if(temp == -1)
            {
                printf("Cannot calculate Inverse\n");
                exit(1);
            }

            for(int k=0; k<=n; k++)
            {
                double temp2= augMat[i][k];
                augMat[i][k]= augMat[temp][k];
                augMat[temp][k]= temp2;

                if(k!=n)
                {
                    double temp2= inverse[i][k];
                    inverse[i][k]= inverse[temp][k];
                    inverse[temp][k]= temp2;
                }
            }
        }

        pivot= augMat[i][i];

        for(int j=i+1; j<n; j++)
        {
            double ratio= augMat[j][i]/ pivot;
            for(int k=0; k<n+1; k++)
            {
                augMat[j][k] = augMat[j][k]- (ratio* augMat[i][k]);
                if(k!=n)
                {
                    inverse[j][k]= inverse[j][k]- (ratio* inverse[i][k]);
                }
                if(fabs(augMat[j][k]) < EPS)
                {
                    augMat[j][k]= 0;
                }
            }
        }
    }

    double det= determinant();
    printf("det= %lf\n", det);

    printMatrix();

    for(int i=n-1; i>=0; i--)
    {
        double pivot= augMat[i][i];
        for(int j=i-1; j>=0; j--)
        {
            double ratio = augMat[j][i]/ pivot;
            for(int k=0; k<n+1; k++)
            {
                augMat[j][k] = augMat[j][k]- (ratio* augMat[i][k]);
                if(k!=n)
                {
                    inverse[j][k]= inverse[j][k]- (ratio* inverse[i][k]);
                }
                if(fabs(augMat[j][k]) < EPS)
                {
                    augMat[j][k]= 0;
                }
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        double temp= augMat[i][i];
        for(int j=0; j<n+1; j++)
        {
            augMat[i][j]= augMat[i][j]/ temp;
            if(j!=n)
            {
                inverse[i][j]= inverse[i][j]/ temp;
            }
        }
    }
}


int main()
{
    solveTheProblem();
    printMatrix();
}