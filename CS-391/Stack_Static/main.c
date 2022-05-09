#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct
{
    int data[MAX];
    int top;
}Stack;

//Prototype declaration
void initialisation (Stack *);
void push (Stack *, int );
int pop (Stack *);
void Display(Stack);

int main()
{
    int ch;
    int n;
    char ch2;
    Stack stk;

    initialisation(&stk);

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
            push(&stk,n);
            break;

        case 2:
            printf("%d \n",pop(&stk));
            break;

        case 3:
            printf("%d \n",peek(&stk));
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
    printf("Stack Elements: \n");
    Display(stk);
}


void initialisation(Stack *stk)
{
    stk->top=-1;
}

void push(Stack *stk, int val)
{
    if(stk->top!=MAX-1)
        stk->data[++(stk->top)]=val;
    else
        printf("Stack Overflow \n");
}

int pop(Stack *stk)
{
    if(stk->top!=-1)
        return stk->data[(stk->top)--];
    else
        printf("Stack Underflow \n");
}

int peek(Stack stk)
{
    if(stk.top!=-1)
        return stk.data[stk.top];
    else
    {
        printf("Stack Underflow \n");
        exit(1);
    }
}

void Display(Stack stk)
{
    while(stk.top!=-1)
    {
        printf("%d ",stk.data[stk.top--]);
    }
    printf("\n");
}
