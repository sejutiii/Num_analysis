#include<stdio.h>

int matA[3][3];
int matB[3][3];
int matC[3][3];

int row_A= 3;
int col_A= 3;
int row_B= 3;
int col_B= 3;

void getInput()
{
    printf("Enter the matrix A:\n");
    for(int i=0; i<row_A; i++)
    {
        for(int j=0; j<col_A; j++)
        {
            scanf("%d", &matA[i][j]);
        }
    }

    printf("Enter the matrix B:\n");
    for(int i=0; i<row_B; i++)
    {
        for(int j=0; j<col_B; j++)
        {
            scanf("%d", &matB[i][j]);
        }
    }
}

void printOutput()
{
    printf("The output matrix is:\n");
    for(int i=0; i<row_A; i++)
    {
        for(int j=0; j<col_B; j++)
        {
            printf("%d ", matC[i][j]);
        }
        printf("\n");
    }
}

int multiplication()
{
    for(int i=0; i<row_A; i++)
    {
        for(int j=0; j<col_B; j++)
        {
            int sum=0;
            for(int k=0; k<row_B; k++)
            {
                sum+= matA[i][k] *matB[k][j];
            }
            matC[i][j]= sum;
        }
    }
}

int main()
{
    getInput();
    multiplication();
    printOutput();
}
