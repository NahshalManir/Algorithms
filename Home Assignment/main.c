#include <stdio.h>
#include <stdlib.h>
#define ROWS 10
#define COLS 10

void Matrices_Sum()
{
    int i,j,rows,cols;
    printf("Enter number of rows: ");
    scanf("%d",&rows);
    printf("Enter number of columns: ");
    scanf("%d",&cols);
    int m1[rows][cols];
    int m2[rows][cols];
    int sum[rows][cols];

     if(rows<1 || cols <1 || rows>ROWS || cols>COLS)
    {
        printf("Wrong dimensions, Array addition not possible");
        exit(1);
    }

    printf("Enter elements of first matrix: \n");
    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            scanf("%d",&m1[i][j]);
        }
    }

    printf("Enter elements of second matrix: \n");
    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            scanf("%d",&m2[i][j]);
        }
    }

    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            sum[i][j]=m1[i][j]+m2[i][j];
        }
    }

    printf("Sum of the two matrices is: \n");
    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            printf("%d\t",sum[i][j]);
        }
        printf("\n");
    }
}

void Multi_Array()
{
    int i,j,k;
    i=j=k=2;
    int M[i][j][k];

    printf("Enter elements: \n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            for(k=0;k<2;k++)
            {
                scanf("%d",&M[i][j][k]);
            }
        }
    }

    printf("Elements are: \n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            for(k=0;k<2;k++)
            {
                printf("%d\t",M[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}


int main()
{
    int n;
    printf("1. Add two Matrices \n");
    printf("2. Display 2x2x2 Array \n");
    printf("Enter choice \n");
    scanf("%d",&n);

    switch(n)
    {
    case 1:
        Matrices_Sum();
        break;
    case 2:
        Multi_Array();
        break;
    default:
        printf("Wrong choice \n");
    }

    return(0);

}

