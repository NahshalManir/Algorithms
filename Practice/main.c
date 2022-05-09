#include <stdio.h>
#include <stdlib.h>

/*void perm(char s[],int k)
{
    static int A[10]={0};
    static char Res[10];
    int i;

    if(s[k]=='\0')
    {
        Res[k]='\0';
        printf(Res);
        printf("\n");
    }

    else
    {
        for(i=0;s[i]!='\0';i++)
        {
            if(A[i]==0)
            {
                Res[k]=s[i];
                A[i]=1;
                perm(s,k+1);
                A[i]=0;
            }
        }
    }
}

void swap(char *x, char *y)
{
    char temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void perm_swap(char s[], int l, int h)
{
    int i;
    if(l==h)
    {
        printf(s);
        printf("\n");
    }
    else
    {
        for(i=0;s[i]!='\0';i++)
        {
            swap(&s[l],&s[i]);
            perm_swap(s,l+1,h);
            swap(&s[l],&s[i]);
        }
    }
}

int main()
{
    char s[]="ABC";
    perm_swap(s,0,2);
    return 0;
}*/

/*int fact(int n)
{
    printf("%d",n);
    if(n<0)
    {
        printf("ERROR: Factorial of negative number number not possible");
        exit(1);
    }
    if(n==0 || n==1)
        return 1;
    else
        return(n*fact(n-1));
}

int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    printf("Factorial of %d: %d",n,fact(n));

    return 0;
}*/

void swap(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int gcd(int a, int b)
{
    if(a%b==0)
        return b;
    else
        return(gcd(b,a%b));

}

int Ackermann(int m, int n);

int main(int argc, char *argv[])
{
    /*printf("Count of arguments: %d\n",argc);
    for(int i=0;i<argc;i++)
        printf("%s\n",argv[i]);*/
    //printf("%s\n",argv[1]);
    int x,y;
    if(argc!=3)
    {
        printf("\nUsage: %s n1 n2\n",argv[0]);
        exit(0);
    }
    x=atoi(argv[1]);
    y=atoi(argv[2]);
    printf("\nAckermann value for(%d %d):%d\n",x,y,Ackermann(x,y));
    return 0;
}

int Ackermann(int m, int n)
{
    if(m<0 || n<0)
    {
        printf("ERROR: Validate parameters");
        exit(1);
    }
    if(m==0)
        return n+1;
    if(n==0)
        return Ackermann(m-1,1);
    return Ackermann(m-1, Ackermann(m,n-1));
}


