#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"

typedef struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} Node;

Node *root = NULL;

void Treecreate() {
    Node *p,*t;
    int x;
    struct Queue q;
    create(&q,100);

    printf("Enter root value: ");
    scanf("%d",&x);
    root=(Node *)malloc(sizeof(Node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);

    while(!isEmpty(q))
    {
        p=dequeue(&q);
        printf("Enter left child of %d: ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(Node *)malloc(sizeof(Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }
        printf("Enter right child of %d: ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(Node *)malloc(sizeof(Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }

    }

}

void Preorder(Node *p)
{
    if(p)
    {
        printf("%d ",p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);

    }
}

void Inorder(Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);

    }
}

void Postorder(Node *p)
{
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ",p->data);
    }
}

void IPreorder(Node *p)
{
    struct Stack stk;
    Stackcreate(&stk,100);

    while(p || !isEmptyStack(stk))
    {
        if(p)
        {
            printf("%d ",p->data);
            push(&stk,p);
            p=p->lchild;
        }
        else
        {
            p=pop(&stk);
            p=p->rchild;
        }
    }
}

void IInorder(Node *p)
{
    struct Stack stk;
    Stackcreate(&stk,100);

    while(p || !isEmptyStack(stk))
    {
        if(p)
        {
            push(&stk,p);
            p=p->lchild;
        }
        else
        {
            p=pop(&stk);
            printf("%d ",p->data);
            p=p->rchild;
        }
    }
}

void IPostorder(Node *p) {
    if(p==NULL) {
        printf("Empty Tree \n");
        return;
    }

    struct Stack stk;
    Stackcreate(&stk,100);

    do
    {
        while(p!=NULL)
        {
            if(p->rchild!=NULL)
                push(&stk, p->rchild);
            push(&stk, p);
            p=p->lchild;
        }

        p=pop(&stk);
        if(p->rchild!=NULL && isEmptyStack(stk) != 1 && p->rchild==peek(stk))
        {
            pop(&stk);
            push(&stk, p);
            p=p->rchild;
        }
        else
        {
            printf("%d ",p->data);
            p=NULL;
        }
    }while(isEmptyStack(stk));

    deleteStack(&stk);
}

void MorrisPreorder(Node *p) {
    while(p != NULL) {
        if(!p->lchild) {
            printf("%d ", p->data);
            p = p->rchild;
        } else {
            Node *temp = p->lchild;
            while(temp->rchild && temp->rchild != p) 
                temp = temp->rchild;
            if(temp->rchild == NULL) {
                temp->rchild = p;
                printf("%d ", p->data);
                p = p->lchild;
            } else {
                temp->rchild = NULL;
                p = p->rchild;
            }
        }
    }
    printf("\n");
}

void MorrisInorder(Node *p) {
    while(p != NULL) {
        if(!p->lchild) {
            printf("%d ", p->data);
            p = p->rchild;
        } else {
            Node *temp = p->lchild;
            while(temp->rchild && temp->rchild != p) 
                temp = temp->rchild;
            if(temp->rchild == NULL) {
                temp->rchild = p;
                p = p->lchild;
            } else {
                temp->rchild = NULL;
                printf("%d ", p->data);
                p = p->rchild;
            }
        }
    }
    printf("\n");
}

int count(Node *root)
{
    int x,y;
    if(root)
    {
        x=count(root->lchild); //return count(root->lchild)+count(root->rchild)+1
        y=count(root->rchild);
        return x+y+1;
    }
    return 0;
}

int height(Node *root)
{
    if(root==0)
        return 0;
    int x=height(root->lchild);
    int y=height(root->rchild);
    return x > y ? x + 1 : y + 1;
}

void LevelOrder(Node *p)
{
    struct Queue q;
    create(&q,100);
    printf("%d ",p->data);
    enqueue(&q,p);

    while(!isEmpty(q))
    {
        p=dequeue(&q);
        if(p->lchild)
        {
            printf("%d ",p->lchild->data);
            enqueue(&q,p->lchild);
        }
        if(p->rchild)
        {
            printf("%d ",p->rchild->data);
            enqueue(&q,p->rchild);
        }
    }
    printf("\n");
}

int main()
{
    Treecreate();

    //Inorder(root);
    printf("Count: %d\n",count(root));
    printf("Height: %d\n",height(root));
    LevelOrder(root);
    // IPostorder(root);
    MorrisInorder(root);
    MorrisPreorder(root);

    return 0;
}
