#include <stdio.h>
#include <stdlib.h>

int BinarySearch()
{
    int i,n,num,mid,pos=-1;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int A[n];
    printf("Enter %d elements: ",n);
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    printf("Enter element to be found: ");
    scanf("%d",&num);

    int l=0,h=n-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(A[mid]==num)
            return mid;
        else if(A[mid]<num)
            l=mid+1;
        else
        h=mid-1;
    }
    return pos;
}

int main()
{
    printf("%d",BinarySearch());
    return 0;
}
