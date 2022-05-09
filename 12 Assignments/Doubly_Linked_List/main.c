#include <stdio.h>
#include <stdlib.h>

typedef struct d_linked_list
{
    int data;
    struct d_linked_list *prev,*next;
}NODE;

void initialization(NODE **aah)
{
    *aah=NULL;
}

void insert_in_sorted_order (NODE ** aah, int n)
{
    NODE *cur, *prev,*t;
    t=(NODE *) malloc(sizeof(NODE));
    t->data = n;
    t->prev = NULL;
    t->next = NULL;
    for(cur=*aah, prev=NULL; cur && n>cur->data; cur=cur->next)
        prev=cur;
    t->next=cur;
    if(cur !=NULL)  /* Make sure that the pointer cur actually exists.*/
        cur->prev=t;
    if (prev) /* Make sure that the pointer prev actually exists.*/
    {
        prev->next=t;
        t->prev=prev;
    }
    else  /* insert at the beginning. */
    {
        *aah=t;
        t->prev=NULL;
    }
}


/*      Sequential Insertion                            */

/*  Remove the condition n>cur->data from the function insert_in_sorted_order */




void insert_at_end(NODE ** aah, int n)
{
    NODE *cur, *prev,*t;
    t=(NODE *) malloc(sizeof(NODE));
    t->data = n;
    t->prev = NULL;
    t->next = NULL;
    for( cur=*aah, prev=NULL; cur ; cur=cur->next)
        prev=cur;
    t->next=cur;
    if(cur !=NULL)  /* Make sure that the pointer cur actually exists.*/
        cur->prev=t;
    if (prev) /* Make sure that the pointer prev actually exists.*/
    {
        prev->next=t;
        t->prev=prev;
    }
    else  /* insert at the beginning. */
    {
        *aah=t;
        t->prev=NULL;
    }
}

void insert_at_beginning(NODE **aah, int n)
{
    NODE * t;
    t=(NODE *) malloc(sizeof(NODE));
    t->data = n;
    t->prev = NULL;
    t->next = *aah;
    if(*aah != NULL)
        (*aah)->prev=t;
    *aah=t;
}

void deletion (NODE **aah, int n)
{
    int  found=0;
    NODE *prev,*cur,*t;
    for(prev=NULL,cur=*aah; cur; )
    {
        if (n==cur->data)
        {
            found=1;
            t=cur;
            if(prev==NULL)
            {
                *aah=cur->next;
                if(cur->next !=NULL)
                    (cur->next)->prev=NULL;

            }
            else
            {
                prev->next=cur->next;
                if(cur->next !=NULL)
                    (cur->next)->prev=prev;
            }
            free(t);
            printf("Successfully deleted %d \n",n);
        }
        else
        {
           prev=cur;
           cur=cur->next;
        }
     }
     if(!found)
     {
           printf("Item not found \n");
           exit(1);
     }
}

void forward_display (NODE *ah)
{
     NODE * cur;
     for (cur=ah; cur; cur=cur->next)
                printf("%d ",cur->data);

}

void reverse_display (NODE *ah)
{
     NODE * cur;
     for (cur=ah; cur->next; cur=cur->next); /* go to the last node */
     for (;cur; cur=cur->prev)
           printf("%d ",cur->data);
}

int main()
{
    NODE *sort_l,*ser_l;
    int ch,n;
    char ch2;

    //initialization(&sort_l);
    //initialization(&ser_l);
    while(1)
    {
        printf("*******MENU******* \n");
        printf("1.  Enter Element in Sorted Order \n");
        printf("2.  Enter Element at the beginning \n");
        printf("3.  Enter element at the end \n");
        printf("4.  Delete from Sorted List \n");
        printf("5.  Delete from Serial (Non Sorted) List \n");
        printf("6.  Forward Display \n");
        printf("7.  Reverse Display \n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter Element to be inserted in Sorted Order: ");
                scanf("%d",&n);
                insert_in_sorted_order(&sort_l,n);
                break;

            case 2:
                printf("Enter Element to be inserted at the beginning (Non Sorted): ");
                scanf("%d",&n);
                insert_at_beginning(&ser_l,n);
                break;

            case 3:
                printf("Enter Element to be inserted at the end (Non Sorted): ");
                scanf("%d",&n);
                insert_at_end(&ser_l,n);
                break;

            case 4:
                printf("Enter element to be deleted form Sorted List: ");
                scanf("%d",&n);
                deletion(&sort_l,n);
                break;

            case 5:
                printf("Enter element to be deleted form Non Sorted List: ");
                scanf("%d",&n);
                deletion(&ser_l,n);
                break;

            case 6:
                printf("Sorted List: ");
                forward_display(sort_l);
                printf("Non Sorted List: ");
                forward_display(ser_l);
                break;

            case 7:
                printf("Sorted List: ");
                reverse_display(sort_l);
                printf("Serial List: ");
                reverse_display(ser_l);
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
