#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*top=NULL;

void push(int x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));

    if(t==NULL)
        printf("Stack is full \n");
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}

int pop()
{
    struct Node *t;
    int x=-1;
    if(top==NULL)
        printf("Stack is empty \n");
    else
    {
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

void Display()
{
    struct Node *p;
    p=top;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int OutStackPre(char x)
{
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 3;
    else if(x=='^')
        return 6;
    else if(x=='(')
        return 7;
    else if(x==')')
        return 0;
    return 0;
}

int InStackPre(char x)
{
    if(x=='+' || x=='-')
        return 2;
    else if(x=='*' || x=='/')
        return 4;
    else if(x=='^')
        return 5;
    else if(x=='(')
        return 0;
    return 0;
}

int isOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/'  || x=='(' || x==')' || x=='^')
        return 0;
    else
        return 1;
}

char * InToPost(char *infix)
{
    int i=0,j=0;
    char *postfix;
    int len=strlen(infix);
    postfix=(char *)malloc((len+2)*sizeof(char));

    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
            postfix[j++]=infix[i++];
        else
        {
            if(top==NULL)
                push(infix[i++]);
            else if(OutStackPre(infix[i])>InStackPre(top->data))
                push(infix[i++]);
            else if(OutStackPre(infix[i])==InStackPre(top->data))
            {
                pop();
                i++;
            }
            else
                postfix[j++]=pop();
        }
    }

    while(top!=NULL)
        postfix[j++]=pop();
    postfix[j]='\0';

    return postfix;
}

int main()
{
    char *infix="((a+b)*c)-d^e^f";

    char *postfix=InToPost(infix);

    printf("%s ",postfix);

    return 0;
}
