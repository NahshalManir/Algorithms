#include <stdio.h>
#include<stdlib.h>

typedef struct linked_list
{
    int data;
    struct linked_list *next;
}Stack;

//Prototype Declaration
void initialisation (Stack **);
void push (Stack **, int);
int pop (Stack **);
void enqueue(Stack **, int);
int dequeue(Stack **, Stack **);

int main()
{
    int ch,n;
    char ch2;
    Stack *stk1,*stk2;

    initialisation(&stk1);
    initialisation(&stk2);

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
            enqueue(&stk1,n);
            break;

        case 2:
            printf("%d\n",dequeue(&stk1,&stk2));
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
    Display(&stk1,&stk2);
}

void initialisation(Stack **top)
{
    *top=NULL;
}

void push(Stack **top, int val)
{
    Stack *t;
    t=(Stack *)malloc(sizeof(Stack));
    t->data=val;
    t->next=*top;
    *top=t;
}

int pop(Stack **top)
{
    Stack *t;
    int x;
    if(*top!=NULL)
    {
        t=*top;
        x=t->data;
        *top=(*top)->next;
        free(t);
        return x;
    }
    else
    {
        printf("Stack Underflow \n");
    }
}

int peek(Stack *top)
{
    if(top!=NULL)
    {
        return top->data;
    }
    else
    {
        printf("Stack Underflow \n");
        return;
    }
}

void enqueue(Stack **top1, int val)
{
    push(top1,val);
}

int dequeue(Stack **top1, Stack **top2)
{
    if(*top2==NULL)
    {
        if(*top1==NULL)
        {
            printf("Queue is empty \n");
            return;
        }
        while(*top1!=NULL)
            push(top2,pop(top1));
    }

    return pop(top2);

}

void Display(Stack **top1,Stack **top2)
{
    while(*top2!=NULL)
    {
        printf("%d ",(*top2)->data);
        *top2=(*top2)->next;
    }
    while(*top1!=NULL)
        push(top2,pop(top1));
    while(*top2!=NULL)
    {
        printf("%d ",(*top2)->data);
        *top2=(*top2)->next;
    }

    printf("\n");
}
