#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct stack
{
    char data[MAX];
    int top;
}Stack;

void initializeStack(Stack *stk)
{
    stk->top=-1;
}

void push(Stack *stk, char val)
{
    if(stk->top!=MAX-1)
        stk->data[++(stk->top)]=val;
    else
        printf("Stack Overflow \n");
}

char pop(Stack *stk)
{
    if(stk->top!=-1)
        return stk->data[(stk->top)--];
    else
        printf("Stack Underflow \n");
}

int isOperator(char x)
{
    switch (x)
    {
        case '+':
        case '-':
        case '/':
        case '*':
        return 1;
    }
    return 0;
}

char * preToPost(char *expr)
{
    Stack stk;
    initializeStack(&stk);
    int i,l=strlen(expr),k=0;;
    char *post;
    post=(char *)malloc(sizeof(char)*l);

    for(i=0;i<l;i++)
    {
        if(isOperator(expr[i]))
            push(&stk,expr[i]);
        else
        {
            post[k++]=expr[i];
            while(stk.top!=-1 && stk.data[stk.top]=='#')
            {
                char a=pop(&stk);
                post[k++]=pop(&stk);
            }
            push(&stk,'#');
        }
    }
    post[k++]='\0';
    return post;
}

int main()
{
    char expr[MAX],*post;
    printf("Enter valid Prefix Expression: ");
    scanf("%[^\n]",expr);
    post=preToPost(expr);
    printf("Postfix Expression: ");
    printf("%s",post);

    return 0;
}
