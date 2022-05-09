#include <stdio.h>
#include <stdlib.h>
#define INFINITE 10000

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

int isCyclicUtil(GRAPH G, int v, int visited[], int recStack[])
{
    if(visited[v]==0)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v]=1;
        recStack[v]=1;

        // Recur for all the vertices adjacent to this vertex
        int i;
        for(i=0; i<G.n; i++)
        {
            if (!visited[i] && isCyclicUtil(G,i, visited, recStack))
                return 1;
            else if (recStack[i])
                return 1;
        }

    }
    recStack[v]=0;  // remove the vertex from recursion stack
    return 0;
}

int isCyclic(GRAPH G)
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    int visited[G.n];
    int recStack[G.n];
    for(int i = 0; i <G.n; i++)
    {
        visited[i]=0;
        recStack[i]=0;
    }

    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i=0; i<G.n; i++)
        if (isCyclicUtil(G,i, visited, recStack))
            return 1;

    return 0;
}

int main()
{
    GRAPH G;
    input_graph(&G);

    if(isCyclic(G))
        printf("\nGraph contains cycle \n");
    else
        printf("\nGraph does not contain cycle \n");

    return 0;
}
