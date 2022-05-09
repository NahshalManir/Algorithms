#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int A[],int j, int x)
{
    int l=0,r=j,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(A[mid]<x)
            l=mid+1;
        else
            r=mid-1;
    }

    return l;
}

void InsertionSort(int A[], int n)
{
    int i,j,key,pos;

    for(i=1;i<n;i++)
    {
        key=A[i];
        j=i-1;
        pos=BinarySearch(A,j,key);
        while(j>=pos)
        {
            A[j+1]=A[j];
            j--;
        }
        A[pos]=key;
    }

}

int main()
{
    int i,n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int A[n];
    printf("Enter elements:- \n");
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);

    InsertionSort(A,n);
    printf("Sorted Array:- \n");
    for(i=0;i<n;i++)
        printf("%d ",A[i]);

    return 0;
}
