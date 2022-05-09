#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct bs_tree
{
    int data;
    struct bs_tree *left, *right;
}bs_tree;

typedef struct queue
{
    bs_tree *elements[MAX];
    int front;
    int rear;
}Queue;

// Prototype Declaration
void initialization(bs_tree **);
void Iterative_Insert(bs_tree **, int);
void Recursive_Insert(bs_tree **, int);
void Recursive_Preorder(bs_tree *);
void Recursive_Inorder(bs_tree *);
void Recursive_Postorder(bs_tree *);
void Iterative_Preorder(bs_tree *);
void Iterative_Inorder(bs_tree *);
void Iterative_Postorder(bs_tree *);
void Search(bs_tree *, bs_tree **, bs_tree **, int *, int);
void Delete(bs_tree **, int);
int height (bs_tree *);
void Level_Order_Traversal(bs_tree *);
void remove_tree_memory(bs_tree **);

void initialize_queue(Queue *);
int isEmptyQueue(Queue);
void add_Queue(Queue *, bs_tree *);
bs_tree *delete_Queue(Queue *);


void initialization(bs_tree **root)
{
    *root=NULL;
}

void Iterative_Insert(bs_tree **root, int val)
{
    bs_tree *cur=*root,*t,*p=NULL;

    t=(bs_tree *)malloc(sizeof(bs_tree));
    t->data=val;
    t->left=t->right=NULL;
    if(*root==NULL)
        *root=t;
    else
    {
        while(cur!=NULL)
        {
            p=cur;
            if(val<cur->data)
                cur=cur->left;
            else
                cur=cur->right;
        }
        if(val<p->data)
            p->left=t;
        else
            p->right=t;
    }

}

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

void Recursive_Preorder(bs_tree *root)
{
    if(root)
    {
        printf("%d ",root->data);
        Recursive_Preorder(root->left);
        Recursive_Preorder(root->right);
    }
}

void Recursive_Inorder(bs_tree *root)
{
    if(root)
    {
        Recursive_Inorder(root->left);
        printf("%d ",root->data);
        Recursive_Inorder(root->right);
    }
}

void Recursive_Postorder(bs_tree *root)
{
    if(root)
    {
        Recursive_Postorder(root->left);
        Recursive_Postorder(root->right);
        printf("%d ",root->data);
    }
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

void Search(bs_tree *root, bs_tree **a_x, bs_tree **a_par, int *a_found, int val)
{
    bs_tree *cur=root;
    *a_par=NULL;
    *a_found=0;

    while(cur!=NULL)
    {
        if(val==cur->data)
        {
            *a_x=cur;
            *a_found=1;
            return;
        }
        else if(val<cur->data)
        {
            *a_par=cur;
            cur=cur->left;
        }
        else
        {
            *a_par=cur;
            cur=cur->right;
        }
    }
}

void Delete(bs_tree **root, int val)
{
    bs_tree *in_order_suc=NULL,*x,*par;
    int found;

    if(*root==NULL)
    {
        printf("Empty Tree \n");
        return;
    }

    Search(*root,&x,&par,&found,val);
    if(found==0)
    {
        printf("Element not found \n");
        return;
    }

    if(x->left!=NULL && x->right!=NULL)
    {
        par=x;
        in_order_suc=x->right;
        while(in_order_suc->left!=NULL)
        {
            par=in_order_suc;
            in_order_suc=in_order_suc->left;
        }
        x->data=in_order_suc->data;
        x=in_order_suc;
    }
    if(x->left==NULL && x->right==NULL)
    {

        if(x==*root)
            *root=NULL;
        else if(par->left==x)
            par->left=NULL;
        else
            par->right=NULL;
        free(x);
    }
    else if(x->left!=NULL && x->right==NULL)
    {
        if(x==*root)
            *root=(*root)->left;
        else if(par->left==x)
            par->left=x->left;
        else
            par->right=x->left;
        free(x);
    }
    else if(x->left==NULL && x->right!=NULL)
    {
        if(x==*root)
            *root=(*root)->right;
        else if(par->left==x)
            par->left=x->right;
        else
            par->right=x->right;
        free(x);
    }

}

int max(int x, int y)
{
    return x>y ? x:y;
}

int height (bs_tree *root)
{
    if(root==NULL)
        return 0;
    else
        return (1+max(height(root->left), height(root->right)));
}

int leaf_nodes(bs_tree *root)
{
    if(root==NULL)
        return 0;
    else if(root->left==NULL && root->right==NULL)
        return 1;
    else
        return (leaf_nodes(root->left)+leaf_nodes(root->right));
}

int internal_nodes(bs_tree *root)
{
    if(root==NULL)
        return 0;
    else if(root->left!=NULL && root->right!=NULL)
        return 1;
    else
        return (internal_nodes(root->left)+internal_nodes(root->right));
}

void mirror_image(bs_tree **root)
{
    bs_tree *temp;

    if(*root!=NULL)
    {
        mirror_image(&(*root)->left);
        mirror_image(&(*root)->right);
        temp=(*root)->left;
        (*root)->left=(*root)->right;
        (*root)->right=temp;
    }
}

bs_tree *largest_int(bs_tree *root)
{
    if(root==NULL || root->right==NULL)
        return root;
    else
        return largest_int(root->right);
}

bs_tree *smallest_int(bs_tree *root)
{
    if(root==NULL || root->left==NULL)
        return root;
    else
        return smallest_int(root->left);
}

void initialize_queue(Queue *q)
{
    q->front=-1;
    q->rear=-1;
}

int isEmptyQueue(Queue q)
{
    return (q.front==q.rear);

}

void add_Queue(Queue *q, bs_tree *t)
{
    if(q->rear==MAX-1)
    {
        printf("Queue is Full \n");
        return;
    }
    else
        q->elements[++(q->rear)]=t;
}

bs_tree *delete_Queue(Queue *q)
{
    bs_tree *t;

    if(isEmptyQueue(*q))
    {
        printf("Queue is Empty \n");
        return NULL;
    }
    else
    {
        t=q->elements[++(q->front)];
        if(isEmptyQueue(*q))
            initialize_queue(q);
        return t;
    }
}

void Level_Order_Traversal(bs_tree *root)
{
    bs_tree *t;
    Queue q;
    initialize_queue(&q);

    if(root==NULL)
    {
        printf("Empty Tree \n");
        return;
    }

    add_Queue(&q,root);
    while(!isEmptyQueue(q))
    {
        t=delete_Queue(&q);
        if(t->left!=NULL)
            add_Queue(&q,t->left);
        if(t->right!=NULL)
            add_Queue(&q,t->right);
        printf("%d ",t->data);
    }

    printf("\n");
}

void remove_tree_memory(bs_tree **root)
{
    if(*root!=NULL)
    {
        remove_tree_memory(&(*root)->left);
        remove_tree_memory(&(*root)->right);
        free(*root);
    }
}

int main()
{
    bs_tree *root=NULL,*largest=NULL,*smallest=NULL;
    int ch,n;
    char ch2;

    initialization(&root);

    while(1)
    {
        printf("*******MENU******* \n");
        printf("1.  Enter Element using Recursion \n");
        printf("2.  Enter Element using Iteration \n");
        printf("3.  Recursive Preorder \n");
        printf("4.  Recursive Inorder \n");
        printf("5.  Recursive Postorder \n");
        printf("6.  Iterative Preorder \n");
        printf("7.  Iterative Inorder \n");
        printf("8.  Iterative Postorder \n");
        printf("9.  Delete an element \n");
        printf("10. Determine Height of Tree \n");
        printf("11. Count number of leaf nodes \n");
        printf("12. Count number of internal nodes \n");
        printf("13. Create Mirror Image of Tree \n");
        printf("14. Find largest integer in Tree \n");
        printf("15. Find smallest integer in Tree \n");
        printf("16. Level Order Traversal \n");
        printf("17. Deallocation of Binary Search Tree \n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter element to be inserted using Recursion: ");
                scanf("%d",&n);
                Recursive_Insert(&root,n);
                break;

            case 2:
                printf("Enter element to be inserted using Iteration: ");
                scanf("%d",&n);
                Iterative_Insert(&root,n);
                break;

            case 3:
                if(root==NULL)
                {
                    printf("Empty Tree \n");
                    break;
                }
                Recursive_Preorder(root);
                printf("\n");
                break;

            case 4:
                if(root==NULL)
                {
                    printf("Empty Tree \n");
                    break;
                }
                Recursive_Inorder(root);
                printf("\n");
                break;

            case 5:
                if(root==NULL)
                {
                    printf("Empty Tree \n");
                    break;
                }
                Recursive_Postorder(root);
                printf("\n");
                break;

            case 6:
                Iterative_Preorder(root);
                break;

            case 7:
                Iterative_Inorder(root);
                break;

            case 8:
                Iterative_Postorder(root);
                break;

            case 9:
                if(root==NULL)
                {
                    printf("Empty Tree \n");
                    break;
                }
                printf("Enter element to be deleted: ");
                scanf("%d",&n);
                int found;
                bs_tree *x,*par;
                Search(root, &x,&par,&found,n);

                if(found==0)
                    printf("Element not found \n");
                else
                {
                    Delete(&root,n);
                    printf("%d Deleted \n",n);
                }

                break;

            case 10:
                printf("Height of Tree is: %d \n",height(root));
                break;

            case 11:
                printf("Number of Leaf Nodes: %d \n",leaf_nodes(root));
                break;

            case 12:
                printf("Number of Internal Nodes: %d \n",internal_nodes(root));
                break;

            case 13:
                if(root==NULL)
                    printf("Empty Tree \n");
                else
                {
                    mirror_image(&root);
                    printf("Mirror image successfully created \n");
                }
                break;

            case 14:
                if(root==NULL)
                    printf("Empty Tree \n");
                else
                {
                    largest=largest_int(root);
                    printf("Largest integer is: %d \m",largest->data);
                }
                break;

            case 15:
                if(root==NULL)
                    printf("Empty Tree \n");
                else
                {
                    smallest=smallest_int(root);
                    printf("Smallest integer is: %d \n",smallest->data);
                }
                break;

            case 16:
                if(root==NULL)
                    printf("Empty Tree \n");
                else
                    Level_Order_Traversal(root);
                break;

            case 17:
                if(root==NULL)
                    printf("Empty Tree \n");
                else
                {
                    remove_tree_memory(&root);
                    printf("Deallocation of Binary Search Tree successfull \n");
                }
                break;

            default:
                printf("Wrong choice \n");
        }

        printf("Continue? y/n: ");
        fflush(stdin);
        scanf("%c",&ch2);
        printf("\n");
        if(ch2=='y')
            continue;
        else
            break;
    }

    return 0;
}
