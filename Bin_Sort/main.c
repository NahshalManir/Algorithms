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
    int i,max;
    max=getMax(A,n);
    Node **bins,*cur;
    bins=(Node**)malloc(sizeof(Node *)*(max+1));
    for(i=0;i<max+1;i++)
        bins[i]=NULL;
    for(i=0;i<n;i++)
        Insert(&bins[A[i]],A[i]);

    printf("Sorted Array:- \n");
    for(i=0;i<max+1;i++)
    {
        for(cur=bins[i];cur!=NULL;cur=cur->next)
            printf("%d ",cur->data);
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

    return 0;
}
