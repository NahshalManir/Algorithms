#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 9999999

int matrixChainOrder(int p[], int n) {
    int m[n][n];
    int i, j, k, L, q;

    for (i = 1; i < n; i++)
        m[i][i] = 0;

    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INF;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }


    for(i = 1; i<n; i++) {
        for(j = 1; j<n; j++) {
            if(i > j)
                printf("\t");
            else
                printf("%d\t",m[i][j]);
        }
        printf("\n");
    }


    return m[1][n - 1];
}

/*
int main() {
    int n;
    printf("Enter number of elements:- \n");
    scanf("%d",&n);

    int arr[n];
    printf("Enter chain of %d matrix sequences: ", n);
    for(int i = 0; i < n; i++)
        scanf("%d",&arr[i]);

    for(int x=0;x<n;x++) {
        printf("%d ",arr[x]);
    }
    printf("\n");
    printf("Minimum number of multiplications is %d ", matrixChainOrder(arr, n));

    return 0;
}
*/


int main() {
    FILE *file;
    file = fopen("test.txt", "r");
    char chain[50], *num;

    int arr[50], i=0;

    fgets(chain, 50, file);

    num = strtok(chain, " ");
    while(num != NULL) {
        arr[i++] = atoi(num);
        num = strtok(NULL, " ");
    }

    for(int x=0;x<i;x++) {
        printf("%d ",arr[x]);
    }
    printf("\n");

    printf("Minimum number of multiplications is %d ", matrixChainOrder(arr, i));

    return 0;
}


