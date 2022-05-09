#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char A[]="water";
    char B[]="water";
    int i,H[26]={0};

    for(i=0;A[i]!='\0';i++)
        H[A[i]-97]++;

    for(i=0;B[i]!='\0';i++)
        H[B[i]-97]--;

    for(i=0;i<26;i++)
    {
        if(H[i]!=0)
        {
            printf("Not Anagram");
            return(0);
        }
    }
    printf("Its Anagram");
    return 0;
}
