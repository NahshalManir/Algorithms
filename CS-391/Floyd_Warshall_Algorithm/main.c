#include <stdio.h>
#include <stdlib.h>
#define INFINITE 10000

typedef struct
{
    int n;
    char *V;
    int **wt;
}GRAPH;

void input_graph(GRAPH *);
int min(int a, int b);
void Floyd_Warshall(GRAPH *);
void printSolution(GRAPH);

void input_graph(GRAPH *aG)
{
    int i,j;
    char ans;
    printf("\n Enter the no. of vertices: ");
    scanf("%d",&aG->n);
    aG->V=(char *)malloc(sizeof(char)*aG->n);
    for(i=0;i<aG->n;i++)
        aG->V[i]='A'+i;
    aG->wt=(int **)malloc(sizeof(int *)*aG->n);
    for(i=0; i<aG->n; i++)
        aG->wt[i]=(int *)malloc(sizeof(int)*aG->n);
    for(i=0; i<aG->n; i++)
        for(j=0; j<aG->n; j++)
        {
            printf("\n Is any edge between %d and %d? Answer (Y/N):",i+1,j+1);
            fflush(stdin);
            scanf("%c",&ans);
            if(ans=='y'||ans=='Y')
            {
                printf("\n Enter edge cost between %d and %d :",i+1,j+1);
                scanf("%d",&aG->wt[i][j]);
            }
            else if(i!=j)
                aG->wt[i][j]=INFINITE;
            else
                aG->wt[i][j]=0;
        }
}

int min(int a, int b)
{
    return (a<b ? a:b);
}


void Floyd_Warshall(GRAPH *aG)
{
    GRAPH dist;
    int i,j,k;
    dist.n=aG->n;
    dist.V=(char *)malloc(sizeof(char)*dist.n);
    dist.wt=(int **)malloc(sizeof(int *)*dist.n);
    for(i=0; i<dist.n; i++)
        dist.wt[i]=(int *)malloc(sizeof(int)*dist.n);

    for(i=0;i<aG->n;i++)
        dist.V[i]=aG->V[i];
    for(i=0;i<aG->n;i++)
        for(j=0;j<aG->n;j++)
            dist.wt[i][j]=aG->wt[i][j];

    for(k=0;k<dist.n;k++)
        for(i=0;i<dist.n;i++)
            for(j=0;j<aG->n;j++)
                dist.wt[i][j] = min(dist.wt[i][j],dist.wt[i][k]+dist.wt[k][j]);

    printSolution(dist);
}

void printSolution(GRAPH dist)
{
    printf ("Shortest distances between every pair of vertices \n");
    for (int i=0; i<dist.n; i++)
    {
        for (int j=0; j<dist.n; j++)
        {
            if (dist.wt[i][j]==INFINITE)
                printf("%d -> %d = INF \n",i+1,j+1);
            else
                printf ("%d -> %d = %d \n",i+1,j+1,dist.wt[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    GRAPH G;
    input_graph(&G);
    Floyd_Warshall(&G);

    return 0;
}
