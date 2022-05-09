#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[], int n)
{
    struct Node *t,*last;
    int i;

    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int Length(struct Node *p)
{
    int len=0;

    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}

void Insert(int pos, int x)
{
    struct Node *t,*p=first;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->prev=t->next=NULL;
    t->data=x;

    if(pos==0)
    {
        t->next=first;
        first->prev=t;
        first=t;
    }
    else
    {
        int i;
        for(i=0;i<pos-1;i++)
            p=p->next;
        t->next=p->next;
        t->prev=p;
        if(p->next)
            p->next->prev=t;
        p->next=t;
    }
}

int Delete(int index)
{
    int x;
    struct Node *p=first;

    if(index==1)
    {
        x=first->data;
        first=first->next;
        if(first)
            first->prev=NULL;
        free(p);
    }
    else
    {
        int i;
        for(i=0;i<index-1;i++)
            p=p->next;
        p->prev->next=p->next;
        if(p->next)
            p->next->prev=p->prev;
        x=p->data;
        free(p);
    }
    return x;
}

void Reverse()
{
    struct Node *p=first,*temp;

    while(p)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL)
            first=p;
    }
}

int main()
{
    int A[]={10,20,30,40,50};
    create(A,5);

    printf("\nLength is: %d \n",Length(first));

    Display(first);

    /*Insert(4,100);
    Display(first);

    printf("%d\n",Delete(6));
    Display(first);*/

    Reverse();
    Display(first);
    return 0;
}
