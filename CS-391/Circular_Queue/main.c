#include<stdio.h>
#define MAX 5

typedef struct CQueue
{
    int elements[MAX];
    int front, rear;
}CQueue;

//Prototype Declaration
void initialiseCQueue (CQueue *);
void addCQueue (CQueue *, int);
int deleteCQueue (CQueue *);
int isEmptyCQueue (CQueue );
int isOverflow (CQueue );

void initialiseCQueue (CQueue *q)
{
    q->front =-1;
    q->rear =-1;
}

void addCQueue (CQueue *q, int val)
{
    if(isOverflow(*q))
    {
        printf("Queue is Full \n");
    }
    else
    {
        if (q->front==-1)
            q->front=0;
        q->rear=(q->rear+1)% MAX;
        q->elements[q->rear]=val;
    }
}

int deleteCQueue (CQueue *q)
{
    int data;
    if(isEmptyCQueue(*q))
    {
        printf ("Queue is Empty \n");
        return;
    }
    else
    {
        data = q->elements[q->front];
        if (q->front == q->rear)
            initialiseCQueue (q);
        else
            q->front=(q->front+1)% MAX;
    }

    return data;
}

int isEmptyCQueue (CQueue q)
{
    return (q.front==-1);
}

int isOverflow (CQueue q)
{
    if((q.rear == (q.front-1)%(MAX-1)) || (q.front==0 && q.rear == MAX-1))
        return 1;
    else
        return 0;
}

void Display(CQueue q)
{
    int i;
    if(isEmptyCQueue(q))
        printf("Queue is Empty \n");
    else
    {
        i=q.front;
        do
        {
            printf("%d ",q.elements[i]);
            i=(i+1)%MAX;
        }while(i!=(q.rear+1)%MAX);

        /*for(i=q.front;i!=q.rear+1;i=(i+1)%MAX)
        {
            printf("%d ",q.elements[i]);
        }
        printf("\n");*/
    }

}

int main()
{
    int ch,n;
    char choice;
    CQueue Q;
    initialiseCQueue (&Q);

    while(1)
    {
        printf("*******MENU******* \n");
        printf("1. Add element in Circular Queue \n");
        printf("2. Delete element from Circular Queue \n");
        printf("3. Check if Circular Queue is Full or Empty \n");
        printf("4. Display Circular Queue Elements \n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d",&n);
                addCQueue(&Q,n);
                break;

            case 2:
                if(!isEmptyCQueue(Q))
                {
                    printf("Deleted Element: %d \n",deleteCQueue(&Q));
                }
                else
                    printf("Queue is Empty \n");
                break;

            case 3:
                if(isEmptyCQueue(Q))
                    printf("Queue is Empty \n");
                else
                {
                    printf("Queue is not Empty \n");
                    printf("Queue Elements: ");
                    Display(Q);
                }
                break;

            case 4:
                if(isEmptyCQueue(Q))
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
