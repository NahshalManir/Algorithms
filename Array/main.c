#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n;

    printf("Enter size of array: ");    // Enter size of array
    scanf("%d",&n);

    if(n<1)       // Check if array sie is invalid
    {
        printf("ERROR: Invalid size");     // Display error and exit if size is invalid
        exit(1);
    }

    int arr[n];         // Declare array of size n
    printf("Enter array elements \n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);      // Input elements from user

    printf("Reversed array: \n");
    for(i=n-1;i>=0;i--)           // Print reversed array
        printf("%d ",arr[i]);


}
