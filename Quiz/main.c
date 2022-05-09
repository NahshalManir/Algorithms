#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,blank,star,n;
    scanf("%d",&n);
    if(n<3)
    {
        printf("ERROR");    // Prints error if n is less than 3
        return 0;
    }

    blank=n-1;      // Number of blanks always n-1 for first line
    star=1;         // Pattern always starts with 1 star in the first line
    for(i=0;i<n;i++)
    {
        for(j=1;j<=blank;j++)
            printf(" ");
        blank--;
        for(j=1;j<=star;j++)
            printf("*");
        printf("\n");
        star+=2;
    }

    star=star-4;
    blank=blank+2;
    for(i=0;i<n-1;i++)
    {
        for(j=1;j<=blank;j++)
            printf(" ");
        blank++;
        for(j=1;j<=star;j++)
            printf("*");
        printf("\n");
        star-=2;
    }

    double m=ceil(n*1.0/2);
    blank--;
    star=1;
    for(i=0;i<m;i++)
    {
        for(j=1;j<=blank;j++)
            printf(" ");
        blank--;
        for(j=1;j<=star;j++)
            printf("*");
        printf("\n");
        star+=2;
    }

}
