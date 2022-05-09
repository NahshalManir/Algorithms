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

char peek(Stack stk)
{
    if(stk.top!=-1)
        return stk.data[stk.top];
    else
    {
        printf("Stack Underflow \n");
        exit(1);
    }
}

int isOperand(char ch)
{
    return (ch>='a' && ch<='z') || (ch>='A' && ch<='Z');
}

int prec(char ch)
{
    switch (ch)
    {
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        case '^':
            return 3;
    }
    return -1;
}

void infixToPostfix(char *expr)
{
    Stack stk;
    char post[MAX];
    int i,k=0,l;
    initializeStack(&stk);
    l=strlen(expr);

    for(i=0;i<l;i++)
    {
        if(isOperand(expr[i]))
            post[k++]=expr[i];

        else if (expr[i] == '(')
            push(&stk, expr[i]);

        else if (expr[i] == ')')
        {
            while (stk.top!=-1 && peek(stk)!='(')
                post[k++] = pop(&stk);
            if (stk.top!=-1 && peek(stk) != '(')
            {
                printf("Wrong Expression \n");
                exit(1);
            }
            else
                pop(&stk);
        }

        else // an operator is encountered
        {
            while (stk.top!=-1 && prec(expr[i])<=prec(peek(stk)))
                post[k++] = pop(&stk);
            push(&stk, expr[i]);
        }
    }
    while(stk.top!=-1)
        post[k++]=pop(&stk);
    post[k++]='\0';
    strcpy(expr,post);
}

void reverse(char *s)
{
    int i,l;
    char temp;
    l=strlen(s);

    for(i=0;i<l/2;i++)
    {
        temp=s[i];
        s[i]=s[l-1-i];
        s[l-1-i]=temp;
    }

}

void infixToPrefix(char *expr)
{
    int i,l;
    l=strlen(expr);

    reverse(expr);

    for(i=0;i<l;i++)
    {
        if (expr[i] == '(')
        {
            expr[i] = ')';
            i++;
        }
        else if (expr[i] == ')')
        {
            expr[i] = '(';
            i++;
        }
    }

    infixToPostfix(expr);
    printf("%s\n",expr);
    reverse(expr);
    printf("Prefix Expression: ");
    printf("%s",expr);

}

int main()
{
    char expr[MAX];
    printf("Enter valid Infix expression: ");
    scanf("%[^\n]",expr);

    infixToPrefix(expr);

    return 0;
}
