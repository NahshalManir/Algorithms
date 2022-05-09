#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct queue
{
    int data[MAX];
    int front, rear;
}Queue;

// Prototype Declaration
void initialization(Queue *);
void enqueue(Queue *, int);
int dequeue(Queue *);
int isOverflow(Queue);
int isUnderflow(Queue);
void Display(Queue);

void initialization(Queue *q)
{
    q->front=q->rear=-1;
}

void enqueue(Queue *q, int val)
{
    if(isOverflow(*q))
        printf("Queue is Full \n");
    else
    {
        if(q->front==-1)
            q->front=0;
        q->rear=(q->rear+1)%MAX;
        q->data[q->rear]=val;
    }
}

int dequeue(Queue *q)
{
    int data;

    if(isUnderflow(*q))
    {
        printf("Queue is Empty \n");
        return;
    }
    else
    {
        data=q->data[q->front];
        q->front=(q->front)+1%MAX;
        if(q->front==q->rear)
            initialization(q);
        return data;
    }
}

int isOverflow(Queue q)
{
    if(q.rear==(q.front-1)%(MAX-1) || (q.front==0 && q.rear==MAX-1))
        return 1;
    else
        return 0;
}

int isUnderflow(Queue q)
{
    return(q.front==-1);
}

void Display(Queue q)
{
    int i;

    if(isUnderflow(q))
        printf("Queue is Empty \n");
    else
    {
        i=q.front;
        do
        {
            printf("%d ",q.data[i]);
            i=(i+1)%MAX;
        }while(i!=(q.rear+1)%MAX);
        printf("\n");
    }
}

int main()
{
    Queue q;
    int ch,n;
    char ch2;

    initialization(&q);

    while(1)
    {
        printf("******MENU****** \n");
        printf("1. Enter elements in Circular Queue \n");
        printf("2. Delete elements from Circular Queue \n");
        printf("3. Check if Circular Queue is full \n");
        printf("4. Check if Circular Queue is Empty \n");
        printf("5. Display elements of Circular Queue \n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter any element: ");
                scanf("%d",&n);
                enqueue(&q,n);
                break;

            case 2:
                if(isUnderflow(q))
                    printf("Queue is Empty \n");
                else
                {
                    int x=dequeue(&q);
                    printf("Deleted element is : %d \n",x);
                }
                 break;

            case 3:
                if(isOverflow(q))
                    printf("Circular Queue is full \n)");
                else
                    printf("Circular Queue is not full \n");
                break;

            case 4:
                if(isUnderflow(q))
                    printf("Circular Queue is empty \n");
                else
                    printf("Circular Queue is not empty \n");
                break;

            case 5:
                printf("Circular Queue elements: ");
                Display(q);
                break;

            default:
                printf("Wrong choice \n");
        }
        printf("Continue? y/n ");
        fflush(stdin);
        scanf("%c",&ch2);

        printf("\n");

        if(ch2=='y')
            continue;
        else
            break;
    }

    printf("Circular Queue elements: ");
        Display(q);

    return 0;
}
