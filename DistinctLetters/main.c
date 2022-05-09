#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#include <string.h>

void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

int main()
{
    int i,j;
    char  str[MAX];
    scanf("%s",str);
    int n=strlen(str);

    for(i=0;i<(n-1);i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(str[i]==str[j])
                str[j]=' ';
        }
    }

    for(i=0;i<(n-1);i++)
    {
        for(j=0;j<(n-i-1);j++)
        {
            if(str[j]>str[j+1])
                swap(&str[j],&str[j+1]);
        }
    }
    int ch=' ';
    printf("%d",ch);
    printf("%s",str);
}
