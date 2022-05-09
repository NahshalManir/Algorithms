#include <stdio.h>
#include <stdlib.h>

// Number of vertices in the graph

typedef struct
{
    int n;
    char *V;
    int **wt;
}GRAPH;

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
            printf("\n Is any edge between %d and %d? Answer (Y/N): ",i+1,j+1);
            fflush(stdin);
            scanf("%c",&ans);
            if(ans=='y'||ans=='Y')
                aG->wt[i][j]=1;
            else
                aG->wt[i][j]=0;
        }
}

void printSolution(int color[], int);

/* A utility function to check if
   the current color assignment
   is safe for vertex v i.e. checks
   whether the edge exists or not
   (i.e, graph[v][i]==1). If exist
   then checks whether the color to
   be filled in the new vertex(c is
   sent in the parameter) is already
   used by its adjacent
   vertices(i-->adj vertices) or
   not (i.e, color[i]==c) */
int isSafe(int v, GRAPH G, int color[], int c)
{
    for (int i = 0; i < G.n; i++)
        if (G.wt[v][i] && color[i] == c)
            return 0;
    return 1;
}

/* A recursive utility function
to solve m coloring problem */
void graphColoringUtil(GRAPH G, int m, int color[], int v)
{
    /* base case: If all vertices are
       assigned a color then return true */
    if (v == G.n) {
        printSolution(color, G.n);
        return;
    }

    /* Consider this vertex v and
       try different colors */
    for (int c = 1; c <= m; c++) {
        /* Check if assignment of color
           c to v is fine*/
        if (isSafe(v, G, color, c)) {
            color[v] = c;
            /* recur to assign colors to
               rest of the vertices */
            graphColoringUtil(G, m, color, v + 1);

            /* If assigning color c doesn't
               lead to a solution then remove it */
            color[v] = 0;
        }
    }
}

/* This function solves the m Coloring
   problem using Backtracking. It mainly
   uses graphColoringUtil() to solve the
   problem. It returns false if the m
   colors cannot be assigned, otherwise
   return true and prints assignments of
   colors to all vertices. Please note
   that there may be more than one solutions,
   this function prints one of the
   feasible solutions.*/

/* A utility function to print solution */
void printSolution(int color[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d\t", color[i]);
    printf("\n");
}

// driver program to test above function
int main()
{
    GRAPH G;
    input_graph(&G);
    /* Create following graph and test
       whether it is 3 colorable
      (4)---(3)
       |   / |
       |  /  |
       | /   |
      (1)---(2)
    */

    /*bool graph[V][V] = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };*/
    int m; // Number of colors
    printf("Enter no. of colors: ");
    scanf("%d",&m);

    int color[G.n];
    for(int i = 0; i<G.n; i++)
        color[i] = 0;

    graphColoringUtil(G, m, color, 0);

    return 0;
}
