#include <stdio.h>
#include <stdlib.h>
#define INF 9999999


int min(int a, int b)
{
    return (a<b ? a:b);
}


void printSolution(int n, int dist[n][n])
{
    printf ("Shortest distances between every pair of vertices \n");
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (dist[i][j]==INF)
                printf("%d -> %d = INF \n",i+1,j+1);
            else
                printf ("%d -> %d = %d \n",i+1,j+1,dist[i][j]);
        }
        printf("\n");
    }
}


void Floyd_Warshall(int n, int m[n][n]) {
    int dist[n][n];
    int i,j,k;

    for(i = 0; i<n; i++)
        for(j = 0; j<n; j++)
            dist[i][j]=m[i][j];

    for(k = 0; k<n; k++)
        for(i = 0; i<n; i++)
            for(j = 0; j<n; j++)
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);

    printSolution(n, dist);
}


int main()
{
    FILE *ptr;
    int i,j,n,temp;

    ptr = fopen("test.txt", "r");

    fscanf(ptr, "%d", &n);

    int m[n][n];
    for(i = 0; i<n; i++)
        for(j = 0; j<n; j++) {
            fscanf(ptr, "%d", &temp);
            if(temp == 0 && i != j)
                m[i][j] = INF;
            else
                m[i][j] = temp;
        }

    Floyd_Warshall(n ,m);

    return 0;
}
