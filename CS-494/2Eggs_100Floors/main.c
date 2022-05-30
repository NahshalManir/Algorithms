#include <stdio.h>
#include <stdlib.h>

int min(int a, int b){
    return a < b ? a : b;
}

int max(int a, int b){
    return a > b ? a : b;
}

int egg(int dp[], int n){
    int i;
    if(dp[n] == 0)
        for(i = 1; i <= n; ++i)
            dp[n] = min((dp[n] == 0) ? n : dp[n], 1 + max(i - 1, egg(dp, n-i)));

    return dp[n];
}
int main(){
    int i, n;
    printf("Enter the number of floors: ");
    scanf("%d", &n);

    int dp[n+1];
    for(i = 0; i <= n; i++)
        dp[i] = 0;

    printf("%d", egg(dp, n));
    printf("\n");
    for(i = 0; i <= n; i++)
        printf("%d ", dp[i]);
    printf("\n");

    return 0;
}
