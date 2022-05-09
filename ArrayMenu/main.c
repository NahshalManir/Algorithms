#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int main()
{
    char user_ch[MAX];

    printf("MENU \n");
    printf("What do you want to input? : \n");
    printf("Choices:- \n");
    printf("a (It is the first term of the A.P \n");
    printf("d (It is the common difference between the terms \n");
    printf("n (It is the number of terms in the A.P \n");
    printf("Tn (It is the Nth term of the A.P \n");
    printf("Sn (It is the sum of all terms of the A.P \n");

    scanf("%s",user_ch);
    printf("%s",user_ch);

    return 0;



}
