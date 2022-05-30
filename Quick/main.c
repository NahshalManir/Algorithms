#include <stdio.h>
#include <stdlib.h>
#define MAX 50

void printArray(int A[], int size) {
    int i;
    for(i=0;i<size;i++)
        printf("%d ",A[i]);
    printf("\n");
}

void swap(int *x, int *y) {
    int temp=*x;
    *x=*y;
    *y=temp;
}


int partition(int A[],int l,int h) {
    int pivot=A[h];
    int i=l,j=h;

    while(i<j) {
        while(A[i]<pivot)
            i++;
        while(A[j]>=pivot)
            j--;

        if(i<j)
            swap(&A[i],&A[j]);
    }
    // printf("\n%d\t%d\n", i, j);

    swap(&A[l],&A[h]);
    return i;
}


/*
int partition(int A[],int l,int h)
{
    int pivot=A[l];
    int i=l,j=h;

    while(i<j)
    {
        while(A[i]<=pivot)
            i++;
        while(A[j]>pivot)
            j--;

        if(i<j)
            swap(&A[i],&A[j]);
    }

    swap(&A[j],&A[l]);
    return j;
}
*/

void QuickSort(int A[],int l,int h,int n)
{
    int p;
    /*
    static int c=0;
    printf("%d: ",++c);
    printArray(A,n);
    */
    if(l<h)
    {
        p=partition(A,l,h);
        QuickSort(A,l,p-1,n);
        QuickSort(A,p+1,h,n);
    }
}

int main()
{
    int i, n;
    FILE *ptr;

    ptr = fopen("test.txt", "r");
    fscanf(ptr, "%d", &n);

    int A[n];
    for(i=0;i<n;i++)
        fscanf(ptr, "%d",&A[i]);
    printf("Original: ");
    printArray(A,n);

    QuickSort(A,0,n-1,n);
    printf("Sorted: ");
    printArray(A,n);

    return 0;
}
