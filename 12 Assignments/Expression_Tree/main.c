#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct bs_tree
{
    char data;
    struct bs_tree* left;
    struct bs_tree* right;
}bs_tree;

typedef struct STACK
{
    int top;
    bs_tree *data[MAX];
}STACK;

bs_tree* newNode(bs_tree **aa_root, char data)
{
    *aa_root= (bs_tree *)malloc(sizeof(bs_tree));
    (*aa_root)->data = data;
    (*aa_root)->left = NULL;
    (*aa_root)->right = NULL;

    return (*aa_root);
}

void printInorder(bs_tree *a_node)
{
    if (a_node)
    {
        printInorder(a_node->left);
        printf("%c ",a_node->data);
        printInorder(a_node->right);
    }
}

void initializeStack(STACK *a_top)
{
    a_top->top=-1;
}

void push(STACK *a_top, bs_tree *a_root)
{
    a_top->data[++(a_top->top)]=a_root;
}

bs_tree* pop(STACK *a_top)
{
    return a_top->data[(a_top->top)--];
}

int main()
{
    bs_tree *root=NULL;
    char expr[MAX];
    STACK stk;
    initializeStack(&stk);
    int l;
    bs_tree *x,*y,*t;

    printf("Enter Postfix Expression: ");
    scanf("%[^\n]",expr);
    l=strlen(expr);

    for (int i = 0; i < l; i++)
    {
        if (expr[i]=='+' || expr[i]=='-' || expr[i]=='*' || expr[i]=='/' || expr[i]=='^')
        {
            t=newNode(&root,expr[i]);
            x=pop(&stk);
            y=pop(&stk);
            t->left=y;
            t->right=x;
            push(&stk,t);
        }
        else
        {
            t=newNode(&root,expr[i]);
            push(&stk,t);
        }
    }
    printf("Inorder Traversal of Expression Tree: ");
    printInorder(t);
    printf("\n");
    return 0;
}
