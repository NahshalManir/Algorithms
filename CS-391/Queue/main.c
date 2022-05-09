#include<stdio.h>
#define MAX 5

typedef struct Queue
{
    int elements[MAX];
    int front, rear;
}Queue;

//Prototype Declaration
void initialiseQueue (Queue *);
void addQueue (Queue *, int);
int deleteQueue (Queue *,int *);
int isEmptyQueue (Queue );
int isOverflow (Queue );

void initialiseQueue (Queue *q)
{
    q->front =-1;
    q->rear =-1;
}

void addQueue (Queue *q, int val)
{
    if (q->rear == MAX-1)
        printf("Queue is Full \n");
    else
        q->elements [++(q->rear)]=val;
}

int deleteQueue (Queue *q, int *data)
{
    if(q->front!=q->rear)
    {
        *data=q->elements[++(q->front)];
        if(q->front==q->rear)
        {
            q->front=-1;
            q->rear=-1;
        }
        return 1;
    }
    else
    {
        printf ("Empty Queue \n");
        data=NULL;
        return 0;
    }
}

int isEmptyQueue (Queue q)
{
    return (q.front==q.rear);
}

int isOverflow (Queue q)
{
    return (q.rear == MAX-1);
}

void Display(Queue q)
{
    int i;
    if(isEmptyQueue(q))
        printf("Queue is Empty \n");
    else
    {
        for(i=q.front+1;i!=q.rear+1;i++)
            printf("%d ",q.elements[i]);
        printf("\n");
    }

}

int main()
{
    int ch,n,data;
    char choice;
    Queue Q;
    initialiseQueue (&Q);

    while(1)
    {
        printf("*******MENU******* \n");
        printf("1. Add element in Queue \n");
        printf("2. Delete element from Queue \n");
        printf("3. Check if Queue is Full or Empty \n");
        printf("4. Display Queue Elements \n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d",&n);
                addQueue(&Q,n);
                break;

            case 2:
                if(!isEmptyQueue(Q))
                {
                    deleteQueue(&Q,&data);
                    printf("Deleted Element: %d \n",data);
                }
                else
                    printf("Queue is Empty \n");
                break;

            case 3:
                if(isEmptyQueue(Q))
                    printf("Queue is Empty \n");
                else
                {
                    printf("Queue is not Empty \n");
                    printf("Queue Elements: ");
                    Display(Q);
                }
                break;

            case 4:
                if(isEmptyQueue(Q))
                    printf("Queue is Empty \n");
                else
                {
                    printf("Queue Elements: ");
                    Display(Q);
                }
                break;

            default:
                printf("Wrong Input \n");
        }
        printf("\n");
        printf("Continue y/n: ");
        fflush(stdin);
        scanf("%c",&choice);

        if(choice=='n')
            break;
        printf("\n");
    }

    return 0;
}
