#include <stdio.h>
#include <stdlib.h>
#define INFINITE 100000

typedef struct
{
    int n;
    int *V;
    int **wt;
}GRAPH;

void input_graph(GRAPH *aG)
{
    int i,j;
    char ans;
    printf("\n Enter the no. of vertices: ");
    scanf("%d",&aG->n);
    aG->V=(int *)malloc(sizeof(int)*aG->n);
    for(i=0;i<aG->n;i++)
        aG->V[i]=i+1;
    aG->wt=(int **)malloc(sizeof(int *)*aG->n);
    for(i=0; i<aG->n; i++)
        aG->wt[i]=(int *)malloc(sizeof(int)*aG->n);
    for(i=0; i<aG->n; i++)
        for(j=0; j<aG->n; j++)
        {
            printf("\n Is any edge between %d and %d? Answer (Y/N):",i,j);
            fflush(stdin);
            scanf("%c",&ans);
            if(ans=='y'||ans=='Y')
            {
                printf("\n Enter edge cost between %d and %d :",i,j);
                scanf("%d",&aG->wt[i][j]);
            }
            else if(i!=j)
                aG->wt[i][j]=INFINITE;
            else
                aG->wt[i][j]=0;
        }
}

int uni(int i, int j, int parent[])
{
    if (i!=j)
    {
        parent[j]=i;
        return 1;
    }
    return 0;
}

int find(int i, int parent[])
{
    while(parent[i])
        i=parent[i];
    return i;
}

void Kruskal(GRAPH G)
{
    int i,j,a,b,v,u,edge=1,min,mincost=0,parent[G.n];

    for(i=0; i<G.n; i++)
        parent[i]=0;

    printf("\nThe edges of Minimum Cost Spanning Tree are\n");
    while(edge<G.n)
    {
        for (i=0,min=INFINITE; i<G.n; i++)
            for (j=0; j<G.n; j++)
                if (G.wt[i][j]<min && i!=j)
                {
                    min=G.wt[i][j];
                    a=u=i;
                    b=v=j;
                }

        u=find(u,parent);
        v=find(v,parent);

        if(uni(u,v,parent))
        {
            printf("%d edge (%d,%d) = %d\n", edge++, a, b, min);
            mincost+=min;
        }

    G.wt[a][b]=G.wt[b][a]=INFINITE;
    }

    printf("\nTotal cost of Minimum Spanning Tree = %d\n", mincost);
}

int main()
{
    GRAPH G;
    input_graph(&G);
    Kruskal(G);

    return 0;
}
