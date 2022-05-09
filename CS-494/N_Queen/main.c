#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int *C;
    int no_queen;
}Board;

void initialisation(Board *, int );
void display_Board(Board , int, int *);
int is_safe(Board , int , int );
void n_queen(Board * ,int, int, int *);

void initialisation(Board *B, int n)
{
    int i;
    B->no_queen=n;
    B->C=(int *)malloc(sizeof(int)*(n+1));
    for(i=1;i<=n;i++)
        B->C[i] = -1;
}

void display_Board(Board B, int n, int *a_sol_no)
{
    int i,j;
    printf("\n\n Solution %d: ", ++(*a_sol_no));
    for(i=1;i<=n;i++)
    {
        printf("\n");
        for(j=1;j<=n;j++)
            if(B.C[i]==j)
                printf(" Q");
            else
                printf(" .");
    }
}

int is_safe (Board B, int x, int y)
{
    int i;
    for(i=1; i<x ;i++)
        if (B.C[i]==y || abs(x-i)==abs(y-B.C[i]))
            return 0;
    return 1;
}

void n_queen(Board *B, int k, int n, int *a_sol_no)
{
    int j;
    for(j=1;j<=n;j++)
        if(is_safe(*B,k,j))
        {
            B->C[k]=j;
            if(k==n)
                display_Board(*B,n,a_sol_no);
            else
                n_queen(B,k+1,n,a_sol_no);
        }
}

int main()
{
    Board p;
    int sol_no=0;
    int n;
    printf("Enter no. of Queens for N_Queen: ");
    scanf("%d",&n);

    initialisation(&p,n);
    n_queen(&p,1,n,&sol_no);

    return 0;
}
