#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

// Recursive approach of display function
/*void display(struct Node *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        display(p->next);
    }
}*/

int count(struct Node *p)
{
    int c=0;
    while(p!=NULL)
    {
        c++;
        p=p->next;
    }
    return c;
}

//Recursive approach of count
/*int count(struct Node *p)
{
    if(p!=NULL)
        return (count(p->next)+1);
    else
        return 0;
}*/

int add(struct Node *p)
{
    int sum=0;
    while(p!=NULL)
    {
        sum+=p->data;
        p=p->next;
    }
    return sum;
}

//Recursive approach for sum
/*int add(struct Node *p)
{
    if(p==0)
        return 0;
    else
        return (add(p->next)+p->data);
}*/

int maximum(struct Node *p)
{
    int max=p->data;
    while(p!=0)
    {
        if(p->data>max)
            max=p->data;
        p=p->next;
    }
    return max;
}

//Recursive approach for maximum
/*int maximum(struct Node *p)
{
    int x=0;
    if(p==0)
        return -32768;
    else
    {
        x=maximum(p->next);
        if(x>p->data)
            return x;
        else
            return p->data;
    }
}*/

struct Node *search(struct Node *p, int key)
{
    struct Node *q=NULL;
    while(p)
    {
        if(key==p->data)
        {
            q->next=p->next;   // Move to head code
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

//Recursive search
/*struct Node *search(struct Node *p, int key)
{
    if(p==NULL)
        return NULL;
    if(p->data==key)
        return p;
    return search(p->next,key);
}*/

void insert(struct Node *p,int index, int x)
{
    if(index<0 || index>count(p))
        return;

    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    if(index==0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        p=first;
        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}

void SortedInsert(struct Node *p, int x)
{
    struct Node *t,*q=NULL;

    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;

    if(first==NULL)
        first=t;
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next=first;
            first=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }
}

void Delete(struct Node *p, int index)
{
    int i;
    struct Node *q=NULL;

    if(index==1)
    {
        q=first;
        first=first->next;
    }
    for(i=0;i<index-1;i++)
    {
        q=p;
        p=p->next;
    }
    q->next=p->next;
}

int isSorted(struct Node *p)
{
    struct Node *q=first;
    p=p->next;
    while(p!=NULL)
    {
        if(q->data>p->data)
            return 0;
        q=p;
        p=p->next;
    }
    return 1;
}

void removeDuplicate(struct Node *p)
{
    struct Node *q=p;
    p=p->next;
    while(p!=NULL)
    {
        if(q->data==p->data)
        {
            q->next=p->next;
            p=q->next;
        }
        else
        {
            q=p;
            p=p->next;
        }
    }
}

void Reverse_Data(struct Node *p)
{
    int *A,i=0;
    A=(int *)malloc(sizeof(struct Node)*count(p));
    while(p!=NULL)
    {
        A[i]=p->data;
        p=p->next;
        i++;
    }
    p=first;i--;
    while(p!=NULL)
    {
        p->data=A[i--];
        p=p->next;
    }
}

void Reverse_Links(struct Node *p)
{
    struct Node *q=NULL,*r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void Reverse_Links_Recursive(struct Node *q, struct Node *p)
{
    if(p!=NULL)
    {
        Reverse_Links_Recursive(p,p->next);
        p->next=q;
    }
    else
        first=q;
}

void create2(int A[],int n)
{
    int i;
    struct Node *t,*last;
    second=(struct Node*)malloc(sizeof(struct Node));
    second->data=A[0];
    second->next=NULL;
    last=second;

    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Concatenate(struct Node *p, struct Node *q)
{
    while(p->next!=NULL)
        p=p->next;
    p->next=q;
    q=NULL;
}

void Merge(struct Node *p, struct Node *q)
{
    struct Node *last=NULL;
    if(p->data<q->data)
    {
        third=last=p;
        p=p->next;
        last->next=NULL;
    }
    else
    {
        third=last=q;
        q=q->next;
        last->next=NULL;
    }

    while(p!=NULL && q!=NULL)
    {
        if(p->data<q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p==NULL)
        last->next=q;
    else
        last->next=p;
}

int isLoop(struct Node *p)
{
    struct Node *q=first;
    do
    {
        p=p->next;
        q=q->next;
        if(q==NULL)
            q=NULL;
        else
            q=q->next;
    }while(p!=NULL && q!=NULL && p!=q);

    return p==q?1:0;
}

int main()
{
    struct Node *t1,*t2;

    int A[]={3,5,7,9,11};
    create(A,5);

    /*t1=first->next->next;
    t2=first->next->next->next->next;
    t2->next=t1;*/

    int B[]={2,4,6,8,20,22};
    create2(B,6);
    SortedInsert(first,8);
    SortedInsert(first,2);
    SortedInsert(first,15);
    SortedInsert(first,15);
    display(first);

    /*insert(first,0,10);
    display(first);
    printf("%d\n",count(first));
    printf("%d\n",add(first));
    printf("%d\n",maximum(first));

    struct Node *temp=search(first,7);
    if(temp!=NULL)
        printf("Key is found: %d \n",temp->data);
    else
        printf("Key not found");*/

    //display(first);
    //Delete(first, 1);
    /*display(first);
    if(isSorted(first))
        printf("Linked List is sorted");
    else
        printf("Linked List is not sorted");*/

    /*display(first);
    removeDuplicate(first);
    display(first);*/

    //Reverse_Links_Recursive(NULL,first);
    //display(first);
    //display(second);
    //isLoop(first);
    //printf("%d",isLoop(first));


    return 0;
}
