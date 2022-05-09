#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*Head;

void create(int A[], int n)
{
    int i;
    struct Node *t,*last;
    Head=(struct Node *)malloc(sizeof(struct Node));
    Head->data=A[0];
    Head->next=Head;
    last=Head;

    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *h)
{
    do
    {
        printf("%d ",h->data);
        h=h->next;
    }while(h!=Head);
    printf("\n");
}

void RDisplay(struct Node *h)
{
    static int flag=0;
    if(h!=Head || flag==0)
    {
        flag=1;
        printf("%d ",h->data);
        RDisplay(h->next);
    }
    flag=0;
    printf("\n");
}

void Insert(int pos, int x)
{
    struct Node *p=Head,*t;
    int i;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;

    if(pos==0)
    {
        while(p->next!=Head)
            p=p->next;
        p->next=t;
        t->next=Head;
        Head=t;
    }
    else
    {
        for(i=0;i<pos-1;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
    }
}

int Delete(int pos)
{
    struct Node *q=NULL,*p=Head;
    int i,x;

    if(pos==0)
    {
        while(p->next!=Head)
            p=p->next;
        p->next=Head->next;
        x=Head->data;
        Head=Head->next;
    }
    else
    {
        for(i=0;i<pos-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
    }
    return x;


}

int main()
{
    int A[]={2,3,4,5,6};
    create(A,5);

    Display(Head);
    Insert(3,100);
    Display(Head);
    Delete(5);
    Display(Head);
    return 0;
}
