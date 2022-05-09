#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getMax(int A[], int n)
{
    int i,max=A[0];

    for(i=1;i<n;i++)
    {
        if(A[i]>max)
            max=A[i];
    }

    return max;
}

void CountSort(int A[], int n)
{
    int i,k=0,m;
    m=getMax(A,n);
    int c[m+1];
    memset(c,0,sizeof(c));

    for(i=0;i<n;i++)
        c[A[i]]++;
    for(i=0;i<m+1;i++)
    {
        while(c[i]>0)
        {
            A[k++]=i;
            c[i]--;
        }
    }
}

int main()
{
    int i,n;
    printf("Enter no. of elements:- ");
    scanf("%d", &n);
    int A[n];
    printf("Enter elements:- \n");
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);

    CountSort(A,n);

    printf("Sorted Array:- \n");
    for(i=0;i<n;i++)
        printf("%d ",A[i]);

    return 0;
}
