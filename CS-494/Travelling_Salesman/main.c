#include <stdio.h>
#include <stdlib.h>
#define INFINITE 9999999

void mincost(int n, int m[n][n], int completed[n], int *cost, int city)
{
    int ncity;
    completed[city]=1;

    printf("%d--->",city + 1);
    ncity=least(n, m, completed, cost, city);

    if(ncity==999)
    {
        ncity=0;
        printf("%d",ncity + 1);
        (*cost)+=m[city][ncity];

        return;
    }

    mincost(n, m, completed,cost,ncity);
}

int least(int n, int m[n][n], int completed[n], int *cost, int c)
{
    int i,nc=999;
    int min=999,kmin;

    for(i=0; i<n; i++)
    {
        if((m[c][i]!=0)&&(completed[i]==0))
            if(m[c][i]+m[i][c] < min)
            {
                min=m[i][c]+m[c][i];
                kmin=m[c][i];
                nc=i;
            }
    }

    if(min!=999)
        (*cost)+=kmin;

    return nc;
}

int main()
{
    FILE *ptr;
    int i,j,n,city,cost = 0;

    ptr = fopen("test.txt","r");
    fscanf(ptr,"%d",&n);

    int m[n][n];
    int completed[n];
    for(i = 0; i<n; i++)
        for(j = 0; j<n; j++)
            fscanf(ptr,"%d",&m[i][j]);

    fscanf(ptr, "\nStarting city = %d", &city);

    printf("%d\n",n);
    for(i = 0; i<n; i++) {
        for(j = 0; j<n; j++)
            printf("%d\t",m[i][j]);
        completed[i] = 0;
        printf("\n");
    }
    printf("\n%d\n",city);

    printf("\n\nThe Path is:\n");
    mincost(n, m, completed, &cost, city-1);

    printf("\n\nMinimum cost is %d\n ",cost);

    return 0;
}
