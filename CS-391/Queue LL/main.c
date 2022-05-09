#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct linked_list
{
	int data;
    struct linked_list *next;
}Queue;

void initialisation(Queue **, Queue **);
void enqueue(Queue **, Queue **, int);
int dequeue(Queue **);
void Display(Queue *);

int main()
{
    int ch,n;
    char ch2;
    Queue *q_front=NULL;
    Queue *q_rear=NULL;

    initialisation(&q_front,&q_rear);

    while(1)
    {
        printf("1. Enqueue \n");
        printf("2. Dequeue \n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter element: \n");
            scanf("%d",&n);
            enqueue(&q_front,&q_rear,n);
            break;

        case 2:
            printf("%d\n",dequeue(&q_front));
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

    printf("Queue Elements: ");
    Display(q_front);

    return 0;
}

void initialisation(Queue **front, Queue **rear)
{
    *front=*rear=NULL;
}

void enqueue(Queue **front, Queue **rear, int val)
{
    Queue *t;
    t=(Queue *)malloc(sizeof(Queue));

    t->data=val;
    t->next=NULL;
    if(*front==NULL)
        *front=*rear=t;
    else
    {
        (*rear)->next=t;
        *rear=t;
    }
}

int dequeue(Queue **front)
{
    Queue *t;
    int x;

    if(*front!=NULL)
    {
        t=*front;
        x=t->data;
        *front=t->next;
        free(t);
    }
    else
        printf("Queue is Empty \n");

    return x;
}

void Display(Queue *front)
{
    Queue *p=front;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
