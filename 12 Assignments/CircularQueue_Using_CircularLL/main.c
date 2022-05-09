#include<stdio.h>
#include<stdlib.h>
#define EMPTY_ERROR_CODE -9999

typedef struct scll
{
    int data;
    struct scll *nxt;
}CSLL;

// Prototype Declaration
void initialisation(CSLL **, CSLL **);
int is_empty_queue(CSLL *);
void insert_in_sorted_order(CSLL **, CSLL **, int);
void insert_at_the_rear(CSLL **, CSLL **, int);
int deletion_from_the_front(CSLL **, CSLL **);
void deletion_specified_item(CSLL **, CSLL **, int);
void display(CSLL *);


void initialisation(CSLL **aaf, CSLL **aar)
{
    *aaf=NULL;
    *aar=NULL;
}

int is_empty_queue(CSLL *af)
{
    return(af== NULL);
}


void insert_in_sorted_order(CSLL **aaf, CSLL **aar, int n)
{
    CSLL *cur,*prv,*head=NULL,*t;
    t=(CSLL *)malloc(sizeof(CSLL));
    t->data=n;

    if(*aaf==NULL)
    {
        *aaf=t;
        *aar=t;
        t->nxt=t;
        return;
    }

    for(cur=*aaf,prv=NULL; cur!=head && n>cur->data; cur=cur->nxt)
    {
        head=*aaf;
        prv=cur;
    }
    t->nxt=cur;

    if(prv)
        prv->nxt=t;
    else
    {
        (*aar)->nxt=t;
        *aaf=t;
    }
}

/*Case1: When the first node is inserted in the Circular Queue.


Case 2: When any other node is inserted after the first node in the Circular Queue.*/

void insert_at_the_rear (CSLL **aaf, CSLL **aar, int n)
{
    CSLL *t;
    t=(CSLL *)malloc(sizeof(CSLL));
    t->data=n;

    if(*aaf==NULL)
    {
        *aaf=t;
        *aar=t;
        t->nxt=t;
        return;
    }
    else
    {
        (*aar)->nxt=t;
        t->nxt=*aaf;
        *aar=t;
    }
}


int deletion_from_the_front(CSLL **aaf, CSLL **aar)
{
    CSLL *q;
    int n;
    if(*aaf==NULL)
    {
        printf("Empty Queue \n");
        return EMPTY_ERROR_CODE;
    }
    q=*aaf;
    n=q->data;
    if(*aaf==*aar) /*When there is a single node in the Circular Queue. */
    {
        *aar = NULL;
        *aaf = NULL;
    }
    else
    {
        *aaf=q->nxt;
        (*aar)->nxt=*aaf;
    }
    free(q);
    return n;
}


void deletion_specified_item(CSLL **aaf, CSLL **aar, int n)
{
    CSLL *cur, *prev, *head=NULL;
    int found=0;

    if(*aaf==NULL)
    {
        printf("Empty list \n");
        return;
    }

    for(cur=*aaf, prev=NULL; cur!=head; cur=cur->nxt)
    {
        head=*aaf;
        if(n==cur->data)
        {
            found=1;
            if(cur == *aar)
                *aar=prev;
      /* If the node to be deleted is rear, then its previous node will be declared as the new rear.*/
            if(prev)  /*Case 1: When prev exists.*/
                prev->nxt=cur->nxt;


            else if (cur->nxt != cur) /*Case 2: When prev does not exist and the Circular Queue contains more than one node.*/
            {
                *aaf=cur->nxt;
                (*aar)->nxt=*aaf;
      /* The next part of the rear node will point to the front node.*/
            }
            else  /*Case 3: There is no prev and only a single node is present in the Circular Queue. */
            {
                *aaf=NULL;
                *aar=NULL;
            }
            free(cur);
            printf("\n Successfully deleted the item %d...",n);
            return;
        }
        else
            prev=cur;
    }
    if(found==0)
        printf("Item not found \n");
}


void display(CSLL *af)
{
    CSLL *cur,*head=NULL;
    if(af==NULL)
    {
        printf("Empty Queue \n");
        return;
    }
    printf("\n");
    for(cur=af; cur!=head ; cur=cur->nxt)
    {
        head=af;
        printf("%d ", cur->data);
    }
    printf("\n");
}


int main()
{
    CSLL *f,*r;
    int n,ch;
    char ch2;

    initialisation(&f, &r);

    while(1)
    {
        printf("*******MENU******* \n");
        printf("1. Insert element in Sorted Order \n");
        printf("2. Insert element at Rear \n");
        printf("3. Delete element form Front \n");
        printf("4. Delete specific element \n");
        printf("5. Display Queue elements \n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter element to be inserted: ");
                scanf("%d",&n);
                insert_in_sorted_order(&f,&r,n);
                break;

            case 2:
                printf("Enter Element to be inserted: ");
                scanf("%d",&n);
                insert_at_the_rear(&f,&r,n);
                break;

            case 3:
                printf("Deleted element from front: %d \n",deletion_from_the_front(&f,&r));
                break;

            case 4:
                printf("Enter element to be deleted: ");
                scanf("%d",&n);
                deletion_specified_item(&f,&r,n);
                break;

            case 5:
                display(f);
                break;

            default:
                printf("Wrong choice \n");

        }

        printf("\nContinue? y/n: ");
        fflush(stdin);
        scanf("%c",&ch2);
        printf("\n");

        if(ch=='n')
            break;
    }

    return 0;
}
