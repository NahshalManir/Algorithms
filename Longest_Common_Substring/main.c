#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int max(int x, int y)
{
    return x>y ? x:y;
}

int LCS(char str1[], char str2[])
{
    int LCSuff[strlen(str1)][strlen(str2)],mx=0,i,j,k,mx_i;
    char substr[MAX]="";

    for(i=0;i<=strlen(str1);i++)
        for(j=0;j<=strlen(str2);j++)
        {
            if(i==0 || j==0)
                LCSuff[i][j]=0;
            else if(str1[i-1]==str2[j-1])
            {
                LCSuff[i][j]=1+LCSuff[i-1][j-1];
                if(LCSuff[i][j]>mx)
                {
                    mx=LCSuff[i][j];
                    mx_i=i;
                }
            }
            else
                LCSuff[i][j]=0;
        }

        if(LCSuff[i][j]>mx)
        {
            mx=LCSuff[i][j];
            mx_i=i;
        }
        for(i=mx_i-mx,k=0;i<mx_i;i++,k++)
            substr[k]+=str1[i];


    //printf("%d\n",mx_i);
    printf("\nLongest Common Substring: %s\n",substr);


    return mx;
}

int main()
{
    char str1[MAX],str2[MAX];

    printf("Enter 1st string: ");
    scanf("%[^\n]",str1);
    fflush(stdin);
    printf("Enter 2nd string: ");
    scanf("%[^\n]",str2);

    LCS(str1,str2);

    return 0;
}
