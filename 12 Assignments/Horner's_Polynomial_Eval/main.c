#include <stdio.h>
#include <stdlib.h>

int Horner(int *coeff, int n, int x)
{
    if(n==0)
        return coeff[0];
    return Horner(coeff,n-1,x)*x+coeff[n];
}

int main()
{
	int i,n,x;
	printf("Enter number of terms: ");
	scanf("%d",&n);
	while(n<=0)
    {
        printf("Wrong choice, Enter number of terms again: ");
        scanf("%d",&n);
    }

	int coeff[n];
	for(i=0;i<n;i++)
    {
        if(i<n-2)
            printf("Enter coefficient of x^%d: ",n-i-1);
        else if(i==n-2)
            printf("Enter coefficient of x: ");
        else
            printf("Enter constant term: ");
        scanf("%d",&coeff[i]);
    }
    printf("Enter value of x: ");
    scanf("%d",&x);

    printf("Value of Polynomial is: %d",Horner(coeff,n-1,x));

    return 0;
}
