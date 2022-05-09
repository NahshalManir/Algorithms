#include<stdio.h>
#include<stdlib.h>

typedef struct scll
{
    int data;
    struct scll *nxt;
}CSLL;

/*Prototype Deceleration*/
void initialisation(CSLL **);
void insert_in_sorted_order(CSLL **, int);
void insert_in_serial_order(CSLL **, int);
void deletion(CSLL **, int);
void display(CSLL *);

/*Function Definitions*/
void initialisation(CSLL **aah)
{
    *aah=NULL;
}

void insert_in_sorted_order(CSLL **aah, int n)
{
     CSLL *cur,*prv,*head=NULL,*last, *t;
     /* Creation of a new node t. */
     t=(CSLL *) malloc(sizeof(CSLL));
     t->data=n;
     if(*aah==NULL) /* In case of the first node.*/
     {
        *aah=t;
        t->nxt=t;
        return;
    }
/* Determination of the appropriate place of the newly created node t . The newly created node t must be inserted between prv and cur.*/

/* A circular trip is required.  Start from the head node and finish at head node.*/
    for(cur=*aah, prv=NULL; cur!=head && n>cur->data; cur=cur->nxt)
    {
        head=*aah; /* Set the pointer to the head node every time. */
        prv=cur; /* Before visiting the next node, the current node must be marked as the previous node. */
    }
/* The newly created node t must be inserted between prv and cur.*/
    t->nxt=cur;

    if(prv) /* Check whether previous node exists or not.*/
        prv->nxt=t;
    else /* There is no previous node. The newly created node t will be added at the beginning.*/
    {
      /* Identify the last node that is linked with the head node.*/

         for(last=*aah; last->nxt!=*aah; last=last->nxt);

         last->nxt=t; /* The last node must be linked to the new node.*/

         *aah=t; /*The new node t must be declared as the head node.*/
    }
}


void insert_in_serial_order(CSLL **aah, int n)
{
    CSLL *cur,*t;
    t=(CSLL *)malloc(sizeof(CSLL));
    t->data=n;
    if(*aah==NULL)
    {
        *aah=t;
        t->nxt=t;
        return;
    }

    for(cur=*aah;cur->nxt!=*aah; cur=cur->nxt); /*Go to the last node.*/
    cur->nxt=t; /* Link the last node to the newly created node.*/
    t->nxt=*aah; /* Link the newly created node to the head node.*/

}


void deletion(CSLL **aah, int n)
{
    CSLL *cur, *prev, *head=NULL, *last;
    int found=0;
    if(*aah==NULL)
    {
        printf("Empty list \n");
        return;
    }
/* A head node to head node circular trip is required.  */
    for(cur=*aah, prev=NULL; cur!=head; cur=cur->nxt)
    {
        head=*aah;
        if (n==cur->data) /*Element to be deleted found at the location cur. */
        {
            found=1; /*Set the value of indicator found as 1.*/

            if (prev) /*Check whether the previous node exists or not.*/
                prev->nxt=cur->nxt; /* Removing the link between prv->nxt
                                                  and cur   */
       /*In order to remove the current node, previous node must be linked to the node immediately next to current.*/
            else if (cur->nxt != *aah)
            {
       /* Identify the last node that is linked with the head node.*/
                for(last=*aah; last->nxt!=*aah; last=last->nxt);
                /*There is no previous node. Node to be deleted is head node.*/
                *aah=cur->nxt;
                /* The node next to current node will be marked as head node.*/
                last->nxt=*aah;
                /* The next part of the last node will point to the head node.*/
            }
            else
                *aah=NULL;
            free(cur); /*Deallocation of memory at the location cur.*/
            printf("Successfully deleted the item %d \n",n);
            return;
        }
        else
            prev=cur;
    }
    if (found==0)
        printf("Item not found \n");
}



void display(CSLL *ah)
{
    CSLL *cur,*head=NULL;

    if(ah==NULL)
    {
        printf("Empty list \n");
        return;
    }
/* A head node to head node circular trip is required.  */

    for(cur=ah; cur!=head ; cur=cur->nxt)
    {
        head=ah;
        printf("%d ", cur->data);
    }
    printf("\n");
}

int main()
{
     CSLL *sort_l,*ser_l;
     int n,ch;
     char ch2;
     initialisation(&sort_l);
     initialisation(&ser_l);

     while(1)
     {
         printf("*******MENU******* \n");
         printf("1. Enter element in Sorted Order \n");
         printf("2. Enter element in Serial Order \n");
         printf("3. Delete element form Sorted Order Linked List \n");
         printf("4. Delete element form Serial Order Linked List \n");
         printf("5. Display Sorted Order Linked List \n");
         printf("6. Display Serial Order Linked List \n");
         printf("\n Enter your choice: ");
         scanf("%d",&ch);

         switch(ch)
         {
            case 1:
                printf("Enter element to be entered in Sorted Order: ");
                scanf("%d",&n);
                insert_in_sorted_order(&sort_l,n);
                break;

            case 2:
                printf("Enter element to be entered in Serial Order: ");
                scanf("%d",&n);
                insert_in_serial_order(&ser_l,n);
                break;

            case 3:
                if(sort_l==NULL)
                    printf("Linked List is Empty \n");
                printf("Enter element to be Deleted from Sorted Order: ");
                scanf("%d",&n);
                deletion(&sort_l,n);
                break;

            case 4:
                if(ser_l==NULL)
                    printf("Linked List is Empty \n");
                printf("Enter element to be Deleted from Serial Order: ");
                scanf("%d",&n);
                deletion(&ser_l,n);
                break;

            case 5:
                printf("Sorted Linked List: ");
                display(sort_l);
                break;

            case 6:
                printf("Serial Linked List: ");
                display(ser_l);
                break;

            default:
                printf("Wrong choice \n");
         }

         printf("\n Continue? y/n: ");
         fflush(stdin);
         scanf("%c",&ch2);
         printf("\n");
         if(ch2=='n')
            break;
    }

    printf("Sorted Linked List: ");
    display(sort_l);
    printf("Serial Linked List: ");
    display(ser_l);

    return 0;
}
