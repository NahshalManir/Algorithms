#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int create(int *);
void insert(int *,int);
void deletion(int *,int);
void search(int *,int);
void display(int *,int);


int main()
{
    int *b, n,i;
    //clrscr();
    int ch;
    char g='y';
    printf("\n Enter the number of nodes: ");
    scanf("%d", &n);
    b=(int *)malloc(sizeof(int)*MAX);
    for(i=0;i<n;i++)
    {
        printf("\n Enter the  Element %d: ",i+1);
        scanf("%d", &b[i]);
    }
    do
    {
        printf("\n******Menu******");
        printf("\n1.Delete \n 2.Search \n 3.Insert \n 4.Display\n 5.Exit \n");
        printf("\n Enter your Choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
        case 1:
            deletion(b,n);
            break;

        case 2:
            search(b,n);
            break;

        case 3:
            insert(b,n);
            break;

        case 4:
            display(b,n);
            break;

        case 5:
            exit(1);
            break;

        default:
            printf("\n Enter the correct choice:");
        }
        printf("\n Do u want to continue:::");
        scanf("\n%c", &g);
    }
    while(g=='y'||g=='Y');
    getch();

    return 0;
}

void deletion(int *b, int n)
{
    int i,pos;
    printf("\n Enter the position u want to delete::");
    scanf("%d", &pos);
    if(pos>=n)
    {
        printf("\n Invalid Location::");
    }
    else
    {
        for(i=pos+1;i<n;i++)
        {
            b[i-1]=b[i];
        }
        n--;
    }
    printf("\n The Elements after deletion");
    for(i=0;i<n;i++)
    {
        printf("\t%d", b[i]);
    }
}


void search(int *b, int n)
{
    int i,e;
    printf("\n Enter the Element to be searched:");
    scanf("%d", &e);

    for(i=0;i<n;i++)
    {
        if(b[i]==e)
        {
            printf("Value is in the %d Position", i);
            return;
        }
    }
    printf("Value is not in the list \n");
}


void insert(int *b, int n)
{
    int i,pos,p;
    printf("\n Enter the position u need to insert::");
    scanf("%d", &pos);

    if(pos>=n)
    {
        printf("\n invalid Location::");
    }
    else
    {
        for(i=MAX-1;i>=pos-1;i--)
        {
            b[i+1]=b[i];
        }
        printf("\n Enter the element to insert::\n");
        scanf("%d",&p);
        b[pos]=p;
        n++;
    }

    display(b,n);
}


void display(int b[], int n)
{
    int i;
    printf("\n The Elements of The list ADT are:");
    for(i=0;i<n;i++)
    {
        printf("%d ", b[i]);
    }
}
