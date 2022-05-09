#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

int getMax(int A[], int n)
{
    int i,max=A[0];

    for(i=1;i<n;i++)
    {
        if(A[i]>max)
            max=A[i];
    }

    return max;
}

void Insert(Node **head, int x)
{
    Node *t,*cur=*head,*prev=NULL;
    t=(Node *)malloc(sizeof(Node));
    t->data=x;
    t->next=NULL;

    for(;cur!=NULL;cur=cur->next)
        prev=cur;
    if(prev==NULL)
        *head=t;
    else
        prev->next=t;


}

void BinSort(int A[], int n)
{
    int i,max,d=1,k;
    max=getMax(A,n);
    Node *bins[10]={NULL},*cur;
    while(max>0)
    {
        for(i=0;i<n;i++)
            Insert(&bins[(A[i]/d)%10],A[i]);
        for(i=0,k=0;i<10;i++)
        {
            for(cur=bins[i];cur!=NULL;cur=cur->next)
                A[k++]=cur->data;
            bins[i]=NULL;
        }
        for(i=0;i<n;i++)
            printf("%d ",A[i]);
        printf("\n");
        d=d*10;
        max=max/10;
    }
}

int main()
{
    int i,n;
    printf("Enter no. of elements:- ");
    scanf("%d", &n);
    int A[n];
    printf("Enter elements:- \n");
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);

    BinSort(A,n);

    printf("Sorted Array:- \n");
    for(i=0;i<n;i++)
            printf("%d ",A[i]);

    return 0;
}
