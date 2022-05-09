#include <stdio.h>
#include <stdlib.h>

int isSorted(int A[], int n)
{
    int i;

    for(i=0;i<n-1;i++)
    {
        if(A[i]<=A[i+1])
            continue;
        else
            return 0;
    }

    return 1;
}

void Linear_Search(int A[],int n, int target)
{
    int i;

    for(i=0;i<n;i++)
    {
        if(A[i]==target)
        {
            printf("%d found at index %d in %d passes \n",target,i,i+1);
            return;
        }
    }

    printf("Element not found \n");
}

void Binary_Search(int A[], int n, int target)
{
    int l=0,r=n-1,mid,c=0;

    while(l<=r)
    {
        c++;
        mid=(l+r)/2;
        if(A[mid]==target)
        {
            printf("%d found at index %d in %d passes \n",target,mid,c);
            return;
        }
        else if(target<A[mid])
            r=mid-1;
        else
            l=mid+1;
    }

    printf("Element not found \n");
}

int Interpolation_Search(int arr[], int lo, int hi, int x, int *c)
{
    int pos;

    if (lo<=hi && x>=arr[lo] && x<=arr[hi])
    {
        (*c)++;
        pos = lo+(((double)(hi-lo)/(arr[hi]-arr[lo]))*(x-arr[lo]));

        if (arr[pos]==x)
            return pos;

        if (arr[pos]<x)
            return Interpolation_Search(arr, pos + 1, hi, x,c);

        if (arr[pos]>x)
            return Interpolation_Search(arr, lo, pos - 1, x,c);
    }
    return -1;
}

int main()
{
    int i,n,target,ch;
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

    printf("Enter element to be searched: ");
    scanf("%d",&target);

    printf("*******MENU******* \n");
    printf("1. Linear Search \n");
    printf("2. Binary Search \n");
    printf("3. Interpolation Search \n");
    printf("Enter your choice: ");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:
            Linear_Search(A,n,target);
            break;

        case 2:
            if(!isSorted(A,n))
                printf("Array is not sorted, Cannot perform Binary Search \n");
            else
                Binary_Search(A,n,target);
            break;

        case 3:
            if(!isSorted(A,n))
                printf("Array is not sorted, Cannot perform Interpolation Search \n");
            else
            {
                int pass=0;
                int index=Interpolation_Search(A,0,n-1,target,&pass);
                if (index!=-1)
                    printf("Element found at index %d in %d passes \n",index,pass);
                else
                    printf("Element not found \n");
            }
            break;

        default:
            printf("Wrong choice \n");
    }

    return 0;
}
