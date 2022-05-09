#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int front;
    int rear;
    int size;
    int *Q;
}QUEUE;

void create(QUEUE *q, int size)
{
    q->Q=(int *)malloc(size*sizeof(int));
    q->size=size;
    q->front=q->rear=0;
}

void push_front(QUEUE *q, int x)
{
    if((q->front+q->size-1)%q->size==q->rear)
    {
        printf("Queue is Full \n");
        return;
    }
    else
    {
        q->Q[q->front]=x;
        q->front=(q->front+q->size-1)%q->size;
    }
}

int pop_front(QUEUE *q)
{
    int x;
    if(q->front==q->rear)
    {
        printf("Queue is Empty \n");
        return;
    }
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }

    return x;
}

void push_rear(QUEUE *q, int x)
{
    if((q->rear+1)%q->size==q->front)
    {
        printf("Queue is Full \n");
        return;
    }
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

int pop_rear(QUEUE *q)
{
    int x;
    if((q->rear+q->size-1)%q->size==q->front)
    {
        printf("Queue is Empty \n");
        return;
    }
    else
    {
        q->rear=(q->rear+q->size-1)%q->size;
        x=q->Q[q->rear];
    }

    return x;
}

void Display(QUEUE q)
{
    if(q.front==q.rear)
    {
        printf("Queue is Empty \n");
        return;
    }
    printf("%d %d \n",q.front,q.rear);
    int i=q.front+1;
    if(i==q.size)
        i=0;
    do
    {
        printf("%d ",q.Q[i]);
        i=(i+1)%q.size;
    }while(i!=q.rear);
    printf("\n");
}

int main()
{
    QUEUE q;

    create(&q,5);
    push_front(&q,1);
    push_rear(&q,2);
    pop_front(&q);
    pop_front(&q);
    pop_front(&q);

    Display(q);

    return 0;
}
