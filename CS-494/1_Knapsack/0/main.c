#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}


int knapSack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(K[i - 1][w], val[i - 1]+ K[i - 1][w - wt[i - 1]]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    /*
    for(i = 0; i <= n; i++) {
        for(w = 0; w <= W; w++)
            printf("%d ", K[i][w]);
        printf("\n");
    }
    */

    return K[n][W];
}

// Driver Code
int main() {
    int n;
    printf("Enter no. of elements: ");
    scanf("%d",&n);

    int val[n];
    int wt[n];
    printf("Enter weight and profit of %d elements:- \n", n);
    for(int i = 0; i<n ;i++)
        scanf("%d %d", &wt[i], &val[i]);
    printf("Enter total weight of knapsack: ");
    int W;
    scanf("%d",&W);

    printf("Maximum profit: %d", knapSack(W, wt, val, n));
    return 0;
}

/*

int val[n] = { 60, 100, 120 };
int wt[n] = { 10, 20, 30 };
int W = 50;

ans = 220

*/
