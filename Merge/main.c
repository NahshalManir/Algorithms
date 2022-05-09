#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void printArray(int A[], int size)
{
    int i;
    for(i=0;i<size;i++)
        printf("%d ",A[i]);
    printf("\n");
}

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void Merge(int A[],int l,int mid,int h,int n)
{
    int i=l,j=mid+1,k=l;
    int B[n];

    while(i<=mid && j<=h)
    {
        if(A[i]<A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];
    }
    for(;i<=mid;i++)
        B[k++]=A[i];
    for(;j<=h;j++)
        B[k++]=A[j];

    for(i=l;i<=h;i++)
        A[i]=B[i];
}

void MergeSort(int A[],int l,int h,int n)
{
    int mid;
    static int c=0;
    printf("%d: ",++c);
    printArray(A,n);
    if(l<h)
    {
        mid=(l+h)/2;
        MergeSort(A,l,mid,n);
        MergeSort(A,mid+1,h,n);
        Merge(A,l,mid,h,n);

    }
}

int main()
{
    int n,i;
    scanf("%d",&n);
    if(n<1 || n>MAX)
    {
        printf("ERROR");
        exit(1);
    }
    int A[n];
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    printf("Original: ");
    printArray(A,n);

    MergeSort(A,0,n-1,n);

    printf("Sorted: ");
    printArray(A,n);

    return 0;
}
