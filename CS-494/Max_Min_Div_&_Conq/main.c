#include <stdio.h>
#include <stdlib.h>
#define MAX 999999
#define MIN -999999

// Divide and conquer solution to find the minimum and maximum number in an array
void findMinAndMax(int A[], int low, int high, int *min, int *max)
{
    // if the array contains only one element

    if (low == high)                 // common comparison
    {
        if (*max < A[low])            // comparison 1
            *max = A[low];

        if (*min > A[high])           // comparison 2
            *min = A[high];

        return;
    }

    // if the array contains only two elements

    if (high - low == 1)                // common comparison
    {
        if (A[low] < A[high])       // comparison 1
        {
            if (*min > A[low])       // comparison 2
                *min = A[low];

            if (*max < A[high])      // comparison 3
                *max = A[high];

        }
        else {
            if (*min > A[high])      // comparison 2
                *min = A[high];

            if (*max < A[low])       // comparison 3
                *max = A[low];
        }
        return;
    }

    // find the middle element
    int mid = (low + high) / 2;

    // recur for the left subarray
    findMinAndMax(A, low, mid, min, max);

    // recur for the right subarray
    findMinAndMax(A, mid + 1, high, min, max);
}

int main()
{
    int i,n;

    printf("Enter no. of elements: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter %d elements:-\n", n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    // initialize the minimum element by INFINITY and the
    // maximum element by -INFINITY
    int max = MIN, min = MAX;

    findMinAndMax(arr, 0, n-1, &min, &max);

    printf("The minimum array element is %d\n", min);
    printf("The maximum array element is %d\n", max);

    return 0;
}
