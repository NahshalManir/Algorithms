#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>
#define MAX 50

typedef struct Node
{
    float data;
    struct Node *next;
}Stack;

void initialisation(Stack **top)
{
    *top=NULL;
}

void push(Stack **top,int x)
{
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));

    if(t==NULL)
        printf("stack is full\n");
    else
    {
        t->data=x;
        t->next=*top;
        *top=t;
    }
}

int pop(Stack **top)
{
    struct Node *t;
    float x=-1;

    if(*top==NULL)
    {
        printf("Wrong Expression \n");
        exit(1);
    }
    else
    {
        t=*top;
        *top=(*top)->next;
        x=t->data;
        free(t);
    }
    return x;
}

void Display(Stack *top)
{
    struct Node *p;
    p=top;
    while(p!=NULL)
    {
        printf("%f ",p->data);
        p=p->next;
    }
    printf("\n");
}

int isOperator(char x)
{
    return (x=='+' || x=='-' || x=='*' || x=='/' || x=='^');

}

int Eval(float x1, char operator, float x2)
{
    float ans;

    switch(operator)
    {
        case '+':ans=x1+x2; break;
        case '-':ans=x1-x2; break;
        case '*':ans=x1*x2; break;
        case '/':ans=x1/x2; break;
        case '^':ans=pow(x1,x2); break;
        default: printf("ERROR: Operator undefined \n");
    }
    return ans;
}

float postfix_evaluation (char *pf_expr)
{
    Stack *S;
    int i,j;
    float right, left;
    initialisation(&S);
    for(i=0; pf_expr[i]!='\0'; )
    {
        char t[100]="";
        for(j=0; pf_expr[i] !='\0' && pf_expr[i]!=','; j++,i++)
            t[j]=pf_expr[i];
        if(!isOperator(t[0]))
            push(&S,atof(t));
        else
        {
            right = pop(&S);
            left = pop(&S);
            push(&S,Eval(left,t[0],right));
        }
        if(pf_expr[i]!='\0')
        i++;
    }
    return(pop(&S));
}

int main()
{
    int ch;
    float ans;
    //Stack *stk=NULL;
    char *str;
    str=(char *)malloc((MAX)*sizeof(char));


    printf("Enter postfix expression: ");
    fflush(stdin);
    scanf("%[^\n]%*c", str);
    ans=postfix_evaluation(str);
    printf("Result is %f\n",ans);

    return 0;
}
