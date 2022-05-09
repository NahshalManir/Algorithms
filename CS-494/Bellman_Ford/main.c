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

void printPath(int parent[], int j)
{
    if (parent[j] == - 1)
        return;

    printPath(parent, parent[j]);

    printf("%d ", j+1);
}

void printSolution(int dist[], int n, int parent[], int src)
{
    printf("Vertex\t Distance\tPath");
    for (int i = 0; i < n; i++)
    {
        if(i!=src)
        {
            printf("\n%d -> %d \t  %d\t\t%d ",src+1, i+1, dist[i], src);
            printPath(parent, i);
        }
    }
}

void bellman(GRAPH G, int src)
{
	int dist[G.n];
    int parent[G.n];
    parent[src]=-1;

    for (int i = 0; i < G.n; i++)
        dist[i] = INFINITE;
    dist[src] = 0;

    for(int count = 0; count < G.n-1; count++)
        for(int u = 0; u < G.n; u++)
            for(int v = 0; v < G.n; v++)
                if (G.wt[u][v] && dist[u] != INFINITE && dist[u] + G.wt[u][v] < dist[v])
                {
                    parent[v]=u;
                    dist[v] = dist[u] + G.wt[u][v];
                }

    for(int u = 0; u < G.n; u++)
        for(int v = 0; v < G.n; v++)
            if (G.wt[u][v] && dist[u] != INFINITE && dist[u] + G.wt[u][v] < dist[v])
            {
                printf("Negative weight cycle exists. Bellman Ford will not work\n");
                exit(1);
            }

	printSolution(dist,G.n,parent,src);
}

int main()
{
    GRAPH G;
    input_graph(&G);
    int source;
    printf("Enter source vertex (0-%d): ",G.n-1);
    scanf("%d",&source);

	bellman(G,source);

	printf("\n\n");

	for(int i = 0; i<G.n; i++) {
        for(int j = 0; j<G.n; j++)
            printf("%d ", G.wt[i][j]);
        printf("\n");
	}

	return 0;
}
