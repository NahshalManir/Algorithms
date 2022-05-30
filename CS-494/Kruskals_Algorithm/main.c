#include <stdio.h>
#include <stdlib.h>
#define INF 100000

int uni(int i, int j, int parent[]) {
    if (i!=j) {
        parent[j]=i;
        return 1;
    }
    return 0;
}

int find(int i, int parent[]) {
    while(parent[i])
        i=parent[i];
    return i;
}

void Kruskal(int n, int graph[n][n]) {
    int i,j,a,b,v,u,edge=1,min,mincost=0,parent[n];

    for(i=0; i<n; i++)
        parent[i]=0;

    printf("\nThe edges of Minimum Cost Spanning Tree are\n");
    while(edge<n) {
        for (i=0,min=INF; i<n; i++)
            for (j=0; j<n; j++)
                if (graph[i][j]<min && i!=j) {
                    min=graph[i][j];
                    a=u=i;
                    b=v=j;
                }

        u=find(u,parent);
        v=find(v,parent);

        if(uni(u,v,parent)) {
            printf("%d edge (%d,%d) = %d\n", edge++, a, b, min);
            mincost+=min;
        }

    graph[a][b]=graph[b][a]=INF;
    }

    printf("\nTotal cost of Minimum Spanning Tree = %d\n", mincost);
}

int main() {
    FILE *ptr;

    ptr = fopen("test.txt", "r");
    int n;
    fscanf(ptr, "%d", &n);

    int graph[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            int temp;
            fscanf(ptr, "%d", &temp);
            if(!temp && i == j)
                graph[i][j] = 0;
            else if(!temp && i != j)
                graph[i][j] = INF;
            else
                graph[i][j] = temp;
        }

    Kruskal(n, graph);

    return 0;
}
