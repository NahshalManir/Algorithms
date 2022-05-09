#include <stdio.h>
#include <stdlib.h>

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]

void merge(int arr[], int l, int m, int r, int n)
{
    int i,j;
	int n1 = m - l + 1;
	int n2 = r - m;

	// Create temp arrays
	int L[n1], R[n2];

	// Copy data to temp arrays L[] and R[]
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	// Merge the temp arrays back into arr[l..r]

	// Initial index of first subarray
	i = 0;

	// Initial index of second subarray
	j = 0;

	// Initial index of merged subarray
	int k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of
	// L[], if there are any
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of
	// R[], if there are any
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}

	/*for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");*/
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int arr[],int l,int r,int n)
{
    static int c=0;
    int i;
    printf("%d: ",++c);
    printArray(arr,n);
	if(l>=r)
		return;//returns recursively


	int m =l+ (r-l)/2;
	mergeSort(arr,l,m,n);
	mergeSort(arr,m+1,r,n);
	merge(arr,l,m,r,n);
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ",A[i]);
    printf("\n");
}

// Driver code
int main()
{
	int n,i;
	scanf("%d",&n);
	if(n<1)
    {
        printf("ERROR");
        exit(1);
    }
	int arr[n];
	for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Original: ");
    printArray(arr,n);

	mergeSort(arr, 0, n - 1,n);

	printf("Sorted: ");
	printArray(arr, n);
	return 0;
}


