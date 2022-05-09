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

int main()
{
    int ch,n;
    char ch2;
    Stack *stk=NULL;

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
            printf("%d \n",peek(stk));
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

void Display(Stack *top)
{
    Stack *p=top;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
