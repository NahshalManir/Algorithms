#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

// Prototype Declaration
void initialization(Node **);
void Insert_Sorted(Node **, int);
void Display(Node *);

void initialization(Node **head)
{
    *head=NULL;
}

void Insert_Sorted(Node **head, int val)
{
    Node *cur,*prev=NULL,*t;
    t=(Node *)malloc(sizeof(struct Node));
    t->data=val;

    for(cur=*head;cur!=NULL && val>cur->data;cur=cur->next)
        prev=cur;
    if(prev==NULL)
    {
        t->next=cur;
        *head=t;
    }
    else
    {
        prev->next=t;
        t->next=cur;
    }
}

void Display(Node *head)
{
    Node *cur;
    if(head==NULL)
        printf("Linked List is empty \n");
    else
    {
        for(cur=head;cur;cur=cur->next)
            printf("%d ",cur->data);
    }
    printf("\n");
}

int main()
{
    Node *head;
    int n;
    char ch;

    initialization(&head);

    while(1)
    {
        printf("Enter element to be inserted in Sorted order: ");
        scanf("%d",&n);
        Insert_Sorted(&head,n);
        printf("Continue? y/n ");
        fflush(stdin);
        scanf("%c",&ch);

        printf("\n");
        if(ch=='y')
            continue;
        else
            break;
    }
    printf("Elements in Sorted Order: ");
    Display(head);

    return 0;
}
