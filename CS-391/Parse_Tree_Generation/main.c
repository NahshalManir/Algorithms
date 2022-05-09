#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct
{
    int prc;
    char op;
}TOKEN;

typedef struct PTREE
{
    char opr;
    struct PTREE *left,*right;
}PTREE;

int precedence(char );
void insert(PTREE **, TOKEN[], int, int);
void PreOrder(PTREE *);
void PostOrder(PTREE *);

int main()
{
    PTREE *pt=NULL;
    int i,j,flag=0;
    char expr[MAX];
    TOKEN list[MAX];

    printf("Enter infix expression: ");
    fflush(stdin);
    scanf("%[^\n]",expr);

    for(i=j=0;i<strlen(expr);)
    {
        if(expr[i]=='(')
        {
            flag++;     // To increase the precedence
            i++;
        }
        else if(expr[i]==')')
        {
            flag--;     // To decrease the precedence
            i++;
        }
        else
        {
            list[j].op=expr[i];
            list[j].prc=precedence(expr[i])+flag*10;
            i++;
            j++;
        }
    }

    insert(&pt,list,0,j-1);
    printf("Postfix Expression: ");
    PostOrder(pt);
    printf("\n");
}

int precedence(char c)
{
    if((c>='A' && c<='Z') || (c>='a' && c<='z'))
        return 4;
    else
    {
        switch(c)
        {
            case '^': return 3;
            case '*':
            case '/': return 2;
            case '+':
            case '-': return 1;
            default: exit(1);

        }
    }
}

void insert(PTREE **pt, TOKEN list[MAX], int left, int right)
{
    int i,min,idx;      // idx=index of min. precedence
    if(left>right)
        return;
    else
    {
        idx=left;
        min=list[left].prc;
        for(i=left+1;i<=right;i++)
            if(list[i].prc<=min)
            {
                idx=i;
                min=list[i].prc;
            }
        *pt=(PTREE *)malloc(sizeof(PTREE));
        (*pt)->opr=list[idx].op;
        (*pt)->left=(*pt)->right=NULL;
        insert(&(*pt)->left,list,left,idx-1);
        insert(&(*pt)->right,list,idx+1,right);
    }
}

void PreOrder(PTREE *pt)
{
    if(pt)
    {
        printf("%c",pt->opr);
        PreOrder(pt->left);
        PreOrder(pt->right);
    }
}

void PostOrder(PTREE *pt)
{
    if(pt)
    {
        PostOrder(pt->left);
        PostOrder(pt->right);
        printf("%c",pt->opr);
    }
}
