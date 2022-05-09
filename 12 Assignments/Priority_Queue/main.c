#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct P_Queue
{
    int front,rear;
    int elements[MAX];
    int Pr[MAX];
}P_Queue;

void initialization(P_Queue *q)
{
    q->front=q->rear=-1;
}

void enqueue(P_Queue *q, int data, int p)//Enqueue function to insert data and its priority in queue
{
	int i;
	if(q->rear==MAX-1) //Check if Queue is full
		printf("Queue is full \n");
	else
	{
		if(q->front==q->rear)//if Queue is empty
		{
			q->elements[++(q->rear)]=data;
			q->Pr[q->rear]=p;
		}
		else
		{
			for(i=q->rear;i>=q->front;i--)
			{
				if(p>q->Pr[i])
				{
					q->elements[i+1]=q->elements[i];
					q->Pr[i+1]=q->Pr[i];
				}
				else
					break;
			}
			q->elements[i+1] = data;
			q->Pr[i+1] = p;
			q->rear++;
		}
	}
}

void print(P_Queue q) //print the data of Queue
{
    if(q.front==q.rear)
    {
        printf("Empty Queue \n");
        return;
    }
    int i;
	for(i=q.front+1;i<=q.rear;i++)
	{
		printf("\nElement = %d\tPriority = %d",q.elements[i],q.Pr[i]);
	}
}

int dequeue(P_Queue *q) //remove the data from front
{
    int x;
	if(q->front==q->rear)
		printf("Queue is Empty");
	else
	{
	    ++(q->front);
		printf("deleted Element = %d\t Its Priority = %d",q->elements[q->front],q->Pr[q->front]);
		x=q->elements[q->front];
		if(q->front==q->rear)
			initialization(q);

        return x;
	}

	return;
}

int main()
{
    P_Queue q;
    int data,p,ch;
    char ch2;

    initialization(&q);

    while(1)
    {
        printf("*******MENU******* \n");
        printf("1. Insert element in Priority Queue \n");
        printf("2. Show Priority Queue data \n");
        printf("3. Delete data from Priority Queue \n");
        printf("(Note:- Higher number indicates higher priority.) \n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter data and its priority: ");
                scanf("%d %d",&data,&p);
                enqueue(&q,data,p);
                break;

            case 2:
                print(q);
                break;

            case 3:
                dequeue(&q);
                break;

            default:
                printf("Wrong choice \n");
        }

        printf("\nContinue? y/n: ");
        fflush(stdin);
        scanf("%c",&ch2);
        printf("\n");
        if(ch2=='n')
            break;
    }

    return 0;
}
