#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct bs_tree
{
    int data;
    struct bs_tree *left,*right;
}bs_tree;

void Recursive_Insert(bs_tree **root, int val)
{
    if(*root==NULL)
    {
        *root=(bs_tree *)malloc(sizeof(bs_tree));
        (*root)->data=val;
        (*root)->left=(*root)->right=NULL;
    }
    else if(val<(*root)->data)
        Recursive_Insert(&(*root)->left, val);
    else if(val>(*root)->data)
        Recursive_Insert(&(*root)->right, val);
}

void initialization(bs_tree **root)
{
    *root=NULL;
}

void Iterative_Preorder(bs_tree *root)
{
    bs_tree *stk[MAX];
    int top=-1;

    if(root==NULL)
        printf("Empty Tree \n");

    while(root!=NULL || top!=-1)
    {
        if(root!=NULL)
        {
            printf("%d ",root->data);
            stk[++top]=root;
            root=root->left;
        }
        else
        {
            root=stk[top--];
            root=root->right;
        }
    }
    printf("\n");
}

void Iterative_Inorder(bs_tree *root)
{
    bs_tree *stk[MAX];
    int top=-1;

    if(root==NULL)
        printf("Empty Tree \n");

    while(root!=NULL || top!=-1)
    {
        if(root!=NULL)
        {
            stk[++top]=root;
            root=root->left;
        }
        else
        {
            root=stk[top--];
            printf("%d ",root->data);
            root=root->right;
        }
    }
    printf("\n");
}

void Iterative_Postorder(bs_tree *root)
{
    bs_tree *stk[MAX],*cur=root;
    int top=-1;

    if(root==NULL)
    {
        printf("Empty Tree \n");
        return;
    }

    do
    {
        while(cur!=NULL)
        {
            if(cur->right!=NULL)
                stk[++top]=cur->right;
            stk[++top]=cur;
            cur=cur->left;
        }

        cur=stk[top--];
        if(cur->right!=NULL && cur->right==stk[top])
        {
            top--;
            stk[++top]=cur;
            cur=cur->right;
        }
        else
        {
            printf("%d ",cur->data);
            cur=NULL;
        }
    }while(top!=-1);

    printf("\n");
}


int main()
{
    bs_tree *root=NULL;
    int ch,n;
    char ch2;

    initialization(&root);

    while(1)
    {
        printf("*******MENU******* \n");
        printf("1. Enter element in Binary Search Tree \n");
        printf("2. Iterative Preorder \n");
        printf("3. Iterative Inorder \n");
        printf("4. Iterative Postorder \n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d",&n);
                Recursive_Insert(&root,n);
                break;

            case 2:
                Iterative_Preorder(root);
                break;

            case 3:
                Iterative_Inorder(root);
                break;

            case 4:
                Iterative_Postorder(root);
                break;

            default:
                printf("Wrong choice \n");
        }
        printf("\nContinue ? y/n: ");
        fflush(stdin);
        scanf("%c",&ch2);
        printf("\n");
        if(ch2=='n')
            break;
    }

    return 0;
}
