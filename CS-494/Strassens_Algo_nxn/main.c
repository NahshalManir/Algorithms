#include <stdio.h>
#include <stdlib.h>


/** Funtion to sub two matrices **/
void subtract(int n, int A[n][n], int B[n][n], int C[n][n])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}
/** Funtion to add two matrices **/
void add(int n, int A[n][n], int B[n][n], int C[n][n])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}
/** Funtion to split parent matrix into child matrices **/
void split(int n, int P[n][n], int C[n/2][n/2], int iB, int jB)
{
    for(int i1 = 0, i2 = iB; i1 < n/2; i1++, i2++)
        for(int j1 = 0, j2 = jB; j1 < n/2; j1++, j2++)
            C[i1][j1] = P[i2][j2];
}
/** Funtion to join child matrices into parent matrix **/
void join(int n, int C[n/2][n/2], int P[n][n], int iB, int jB)
{
    for(int i1 = 0, i2 = iB; i1 < n/2; i1++, i2++)
        for(int j1 = 0, j2 = jB; j1 < n/2; j1++, j2++)
            P[i2][j2] = C[i1][j1];
}

void multiply(int n, int A[n][n], int B[n][n], int C[n][n])
{
    // int R[4][4];
    /** base case **/
    if (n == 1)
        C[0][0] = A[0][0] * B[0][0];
    else
    {
        int A11[n/2][n/2];
        int A12[n/2][n/2];
        int A21[n/2][n/2];
        int A22[n/2][n/2];
        int B11[n/2][n/2];
        int B12[n/2][n/2];
        int B21[n/2][n/2];
        int B22[n/2][n/2];

        /** Dividing matrix A into 4 halves **/
        split(n, A, A11, 0, 0);
        split(n, A, A12, 0, n/2);
        split(n, A, A21, n/2, 0);
        split(n, A, A22, n/2, n/2);
        /** Dividing matrix B into 4 halves **/
        split(n, B, B11, 0, 0);
        split(n, B, B12, 0, n/2);
        split(n, B, B21, n/2, 0);
        split(n, B, B22, n/2, n/2);

        /**
          P = (A11 + A22)(B11 + B22)
          Q = B11 (A21 + A22)
          R = A11 (B12 - B22)
          S = A22 (B21 - B11)
          T = B22 (A11 + A12)
          U = (A21 - A11) (B11 + B12)
          V = (A12 - A22) (B21 + B22)
        **/


        int P[n/2][n/2];
        int Q[n/2][n/2];
        int R[n/2][n/2];
        int S[n/2][n/2];
        int T[n/2][n/2];
        int U[n/2][n/2];
        int V[n/2][n/2];
        int t1[n/2][n/2];
        int t2[n/2][n/2];
        int C11[n/2][n/2];
        int C12[n/2][n/2];
        int C21[n/2][n/2];
        int C22[n/2][n/2];

        add(n/2, A11,A22,t1);
        add(n/2, B11,B22,t2);
        multiply(n/2, t1,t2,P);

        add(n/2, A21,A22,t1);
        multiply(n/2, t1,B11,Q);

        subtract(n/2, B12,B22,t2);
        multiply(n/2, A11,t2,R);

        subtract(n/2, B21,B11,t1);
        multiply(n/2, A22,t1,S);

        add(n/2, A11,A12,t1);
        multiply(n/2, t1,B22,T);

        subtract(n/2, A21,A11,t1);
        add(n/2, B11,B12,t2);
        multiply(n/2, t1,t2,U);

        subtract(n/2, A12,A22,t1);
        add(n/2, B21,B22,t2);
        multiply(n/2, t1,t2,V);

        add(n/2, P,S,t1);
        subtract(n/2, V,T,t2);
        add(n/2, t1,t2,C11);

        add(n/2, R,T,C12);
        add(n/2, Q,S,C21);
        add(n/2, P,R,t1);
        subtract(n/2, U,Q,t2);
        add(n/2, t1,t2,C22);

        /**
          C11 = M1 + M4 - M5 + M7
          C12 = M3 + M5
          C21 = M2 + M4
          C22 = M1 - M2 + M3 + M6
          **/

        /** join 4 halves into one result matrix **/
        join(n, C11, C, 0 , 0);
        join(n, C12, C, 0 , n/2);
        join(n, C21, C, n/2, 0);
        join(n, C22, C, n/2, n/2);
    }
}


/** Main function **/
int main ()
{
    int n;

    printf("Strassen Multiplication Algorithm Test:-\n\n");

    printf("Enter order of matrices (Order should be power of 2):-\n");
    scanf("%d", &n);

    int A[n][n];
    int B[n][n];

    /* Accept two 2d matrices */
    printf("Enter %dx%d order matrix A:- \n",n,n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d",&A[i][j]);

    printf("Enter %dx%d order matrix B:- \n",n,n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d",&B[i][j]);


    int C[n][n];
    multiply(n, A, B, C);

    printf("\nProduct of matrices A and  B :- \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ",C[i][j]);
        printf("\n");
    }

    return 0;
}
