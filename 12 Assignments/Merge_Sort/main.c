#include <stdio.h>
#include <stdlib.h>

void Merge(int A[], int l, int mid, int r)
{
    int i=l,j=mid+1,k=l,B[r+1];

    while(i<=mid && j<=r)
    {
        if(A[i]<A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];
    }

    for(;i<=mid;i++)
        B[k++]=A[i];
    for(;j<=r;j++)
        B[k++]=A[j];

    for(i=l;i<=r;i++)
        A[i]=B[i];
}

void Merge_Sort(int A[], int l, int r)
{
    int mid;
    if(l<r)
    {
        mid=(l+r)/2;
        Merge_Sort(A,l,mid);
        Merge_Sort(A,mid+1,r);
        Merge(A,l,mid,r);
    }
}

int main()
{
    int i,n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    while(n<=0)
    {
        printf("Wrong input, Enter number of elements again: ");
        scanf("%d",&n);
    }

    int A[n];
    printf("Enter %d elements:- \n",n);
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);

    Merge_Sort(A,0,n-1);

    printf("Sorted Array: ");
    for(i=0;i<n;i++)
        printf("%d ",A[i]);
}
