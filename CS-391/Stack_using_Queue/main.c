#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list
{
	int data;
    struct linked_list *next;
}Node;

typedef struct
{
    Node *front,*rear;
}Queue;

//Prototype declaration
void initialisation(Queue **);
int isEmpty(Queue **);
void enqueue(Queue **, int);
int dequeue(Queue **);
void Display(Queue *);
void push(Queue **, Queue **, int);
int pop(Queue **);
int peek(Queue **);

int main()
{
    int ch,n;
    char ch2;
    Queue *q1;
    Queue *q2;

    initialisation(&q1);
    initialisation(&q2);

    while(1)
    {
        printf("1. Push \n");
        printf("2. Pop \n");
        printf("3. Peek \n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter element: \n");
            scanf("%d",&n);
            push(&q1,&q2,n);
            break;

        case 2:
            printf("%d \n",pop(&q1));
            break;

        case 3:
            printf("%d \n",peek(&q1));
            break;

        default:
            printf("Wrong input \n");
        }

        printf("Continue? y/n ");
        fflush(stdin);
        scanf("%c",&ch2);
        if(ch2=='n')
            break;
        else
            continue;
    }

    printf("Stack Elements: ");
    Display(q1);

    return 0;
}

void initialisation(Queue **q)
{
    *q=(Queue*)malloc(sizeof(Queue));
    (*q)->front=(*q)->rear=NULL;
}

int isEmpty(Queue **q)
{
    if((*q)->front==NULL)
        return 1;
    else
        return 0;
}

void enqueue(Queue **q, int val)
{
    Node *t;
    t=(Node *)malloc(sizeof(Node));

    t->data=val;
    t->next=NULL;
    if((*q)->front==NULL)
        (*q)->front=(*q)->rear=t;
    else
    {
        (*q)->rear->next=t;
        (*q)->rear=t;
    }
}

int dequeue(Queue **q)
{
    Node *t;
    int x;

    if((*q)->front!=NULL)
    {
        t=(*q)->front;
        x=t->data;
        (*q)->front=t->next;
        free(t);
    }
    else
    {
        printf("Queue is Empty \n");

    }

    return x;
}

void push(Queue **q1, Queue **q2, int val)
{
    while(!isEmpty(q1))
        enqueue(q2,dequeue(q1));

    enqueue(q1,val);

    while(!isEmpty(q2))
        enqueue(q1,dequeue(q2));
}

int pop(Queue **q1)
{
    int x;
    if(!isEmpty(q1))
        x=dequeue(q1);
    else
        printf("Stack Underflow \n");

    return x;
}

int peek(Queue **q1)
{
    int x;
    if(!isEmpty(q1))
        x=(*q1)->front->data;
    else
        printf("Stack Underflow \n");

    return x;
}

void Display(Queue *q)
{
    Node *p=q->front;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
