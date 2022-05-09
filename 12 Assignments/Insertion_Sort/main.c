#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n,key;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    while(n<=0)
    {
        printf("Wrong input, Enter number of elements again: ");
        scanf("%d",&n);
    }

    int arr[n];
    printf("Enter %d elements:- \n",n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    for(i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && key<arr[j])
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }

    printf("Sorted Array: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");

    return 0;

}
