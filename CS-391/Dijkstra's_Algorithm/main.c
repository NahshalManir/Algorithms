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

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], int sptSet[], int n)
{
	// Initialize min value
	int min = INFINITE, min_index;

	for (int v = 0; v < n; v++)
		if (sptSet[v] == 0 && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void printPath(int parent[], int j)
{

    // Base Case : If j is source
    if (parent[j] == - 1)
        return;

    printPath(parent, parent[j]);

    printf("%d ", j);
}

// A utility function to print the constructed distance array
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

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(GRAPH G, int src)
{
	int dist[G.n]; // The output array. dist[i] will hold the shortest
	// distance from src to i

	int sptSet[G.n]; // sptSet[i] will be true if vertex i is included in shortest
	// path tree or shortest distance from src to i is finalized

	// Parent array to store
    // shortest path tree
    int parent[G.n];
    parent[src]=-1;

	// Initialize all distances as INFINITE and sptSet[] as false
	for (int i = 0; i < G.n; i++)
    {
        dist[i] = INFINITE;
        sptSet[i] = 0;
    }

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < G.n - 1; count++)
    {
		// Pick the minimum distance vertex from the set of vertices not
		// yet processed. u is always equal to src in the first iteration.
		int u = minDistance(dist, sptSet,G.n);

		// Mark the picked vertex as processed
		sptSet[u] = 1;

		// Update dist value of the adjacent vertices of the picked vertex.
		for (int v = 0; v < G.n; v++)

			// Update dist[v] only if is not in sptSet, there is an edge from
			// u to v, and total weight of path from src to v through u is
			// smaller than current value of dist[v]
			if (!sptSet[v] && G.wt[u][v] && dist[u] != INFINITE && dist[u] + G.wt[u][v] < dist[v])
            {
                parent[v]=u;
                dist[v] = dist[u] + G.wt[u][v];
            }
	}

	// print the constructed distance array
	printSolution(dist,G.n,parent,src);
}

int main()
{
    GRAPH G;
    input_graph(&G);
    int source;
    printf("Enter source vertex (1-%d): ",G.n);
    scanf("%d",&source);

	dijkstra(G,source-1);

	return 0;
}
