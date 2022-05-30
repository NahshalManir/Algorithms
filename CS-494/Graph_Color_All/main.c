#include <stdio.h>
#include <stdlib.h>

void printSolution(int color[], int);

int isSafe(int v, int n, int graph[n][n], int color[], int c) {
    for (int i = 0; i < n; i++)
        if (graph[v][i] && color[i] == c)
            return 0;
    return 1;
}

void graphColoringUtil(int n, int graph[n][n], int m, int color[], int v) {
    if (v == n) {
        printSolution(color, n);
        return;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, n, graph, color, c)) {
            color[v] = c;

            graphColoringUtil(n, graph, m, color, v + 1);

            color[v] = 0;
        }
    }
}


void printSolution(int color[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d\t", color[i]);
    printf("\n");
}

int main() {
    FILE *ptr;
    ptr = fopen("test.txt", "r");

    int n;
    fscanf(ptr, "%d", &n);

    int graph[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        fscanf(ptr, "%d", &graph[i][j]);

    int m; // Number of colors
    printf("Enter no. of colors: ");
    scanf("%d",&m);

    int color[n];
    for(int i = 0; i<n; i++)
        color[i] = 0;

    graphColoringUtil(n, graph, m, color, 0);

    return 0;
}
