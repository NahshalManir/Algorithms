#include<stdio.h>
#include<stdlib.h>

typedef struct AVL_Tree
{
	int data, ht;
	struct AVL_Tree *left, *right;
}AVL_Tree;

int max(int a, int b)
{
	return ((a>b)? a : b);
}

int height(AVL_Tree *aah)
{
	if(aah == NULL)
		return 0;
	return aah->ht;
}

AVL_Tree * right_rotation(AVL_Tree *y)
{
	AVL_Tree *x = y->left;
	AVL_Tree *T2 = x->right;

	//rotation
	x->right = y;
	y->left = T2;

	//Height update
	y->ht = max(height(y->left), height(y->right))+1;
	x->ht = max(height(x->left), height(x->right))+1;

	return x;
}

AVL_Tree *left_rotation(AVL_Tree *x)
{
	AVL_Tree *y = x->right;
	AVL_Tree *T2 = y->left;

	//rotation
	y->left = x;
	x->right = T2;

	//Height update
	x->ht = max(height(x->left), height(x->right))+1;
	y->ht = max(height(y->left), height(y->right))+1;

	return y;
}


int getBalanceFacor(AVL_Tree *n)
{
	if(n==NULL)
		return 0;
	return (height(n->left)-height(n->right));
}

AVL_Tree *create(int data)
{
    AVL_Tree *n;
    n= (AVL_Tree*) malloc(sizeof(AVL_Tree));
	n->data = data;
	n->left = n->right = NULL;
	n->ht = 1;
	return n;
}

AVL_Tree *insert(AVL_Tree *n, int data)
{
	if(n == NULL)
		return create(data);

	if(data < n->data)
		n->left = insert(n->left, data);
	else if(data>n->data)
		n->right = insert(n->right, data);
	else
		return n;
	//height update
	n->ht = 1 + max(height(n->left), height(n->right));

	int bal=getBalanceFacor(n);

	//LLC
	if(bal > 1 && data<(n->left->data))
		return right_rotation(n);
	//RRC
	if(bal<-1 && data>(n->right->data))
		return left_rotation(n);
	//LRC
	if(bal > 1 && data>(n->left->data))
    {
		n->left = left_rotation(n->left);
		return right_rotation(n);
	}
	//RLC
	if(bal<-1 && data<n->right->data)
    {
		n->right = right_rotation(n->right);
		return left_rotation(n);
	}

	//If already balanced
	return n;
}

void PreOrder(AVL_Tree *n)
{
	if(n != NULL)
    {
		printf("%d ", n->data);
		PreOrder(n->left);
		PreOrder(n->right);
	}
}

void InOrder(AVL_Tree *n)
{
	if(n != NULL)
    {
		InOrder(n->left);
		printf("%d ", n->data);
		InOrder(n->right);
	}
}

void PostOrder(AVL_Tree *n)
{
	if(n != NULL)
    {
		PostOrder(n->left);
		PostOrder(n->right);
		printf("%d ", n->data);
	}
}

int main()
{
	AVL_Tree * root = NULL;
	int n,ch;
	char ch2;

	while(1)
    {
        printf("*******MENU******* \n");
        printf("1.  Enter Element in AVL Tree \n");
        printf("2.  Recursive Preorder \n");
        printf("3.  Recursive Inorder \n");
        printf("4.  Recursive Postorder \n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter element to be inserted in AVL Tree: ");
                scanf("%d",&n);
                root=insert(root, n);
                break;

            case 2:
                if(root==NULL)
                {
                    printf("Empty Tree \n");
                    break;
                }
                PreOrder(root);
                printf("\n");
                break;

            case 3:
                if(root==NULL)
                {
                    printf("Empty Tree \n");
                    break;
                }
                InOrder(root);
                printf("\n");
                break;

            case 4:
                if(root==NULL)
                {
                    printf("Empty Tree \n");
                    break;
                }
                PostOrder(root);
                printf("\n");
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
