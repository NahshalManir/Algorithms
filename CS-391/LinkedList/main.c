#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Linked_List;

void initialization(Linked_List **head)
{
    *head=NULL;
}

void Insert_Sorted(Linked_List **head, int val)
{
    Linked_List *t,*prev=NULL,*cur;
    t=(Linked_List *)malloc(sizeof(Linked_List));
    t->data=val;
    t->next=NULL;

    for(cur=*head;cur!=NULL && val>cur->data;cur=cur->next)
        prev=cur;
    if(prev!=NULL)
    {
        prev->next=t;
        t->next=cur;
    }
    else
    {
        t->next=cur;
        *head=t;
    }
}

void Recursive_Insert_Sorted(Linked_List **head, int val)
{
    Linked_List *t;
    t=(Linked_List *)malloc(sizeof(Linked_List));
    t->data=val;
    t->next=NULL;

    if(*head==NULL)
        *head=t;

    else if(val<(*head)->data)
    {
        t->next=*head;
        *head=t;
    }
    else
        Recursive_Insert_Sorted(&(*head)->next,val);
        
}

void Insert_Serial(Linked_List **head, int val)
{
    Linked_List *t,*prev=NULL,*cur;
    t=(Linked_List *)malloc(sizeof(Linked_List));
    t->data=val;
    t->next=NULL;

    for(cur=*head;cur!=NULL;cur=cur->next)
        prev=cur;
    if(prev!=NULL)
    {
        prev->next=t;
        t->next=cur;
    }
    else
    {
        t->next=cur;
        *head=t;
    }

}

void Recursive_Insert_Serial(Linked_List **head, int val)
{
    if(*head==NULL)
    {
        (*head)=(Linked_List *)malloc(sizeof(Linked_List));
        (*head)->data=val;
        (*head)->next=NULL;
    }
    else
        Recursive_Insert_Serial(&(*head)->next,val);

}

void Display(Linked_List *head)
{
    Linked_List *cur=head;
    while(cur!=NULL)
    {
        printf("%d ",cur->data);
        cur=cur->next;
    }
    printf("\n");
}

void Recursive_Display(Linked_List *head)
{
    Linked_List *cur=head;
    if(cur==NULL)
        return;
    else
    {
        printf("%d ",cur->data);
        Recursive_Display(cur->next);
    }
}

void Delete(Linked_List **head, int val)
{
    Linked_List *cur,*prev=NULL;

    for(cur=*head;cur!=NULL;cur=cur->next)
    {
        if(prev!=NULL && val==cur->data)
        {
            prev->next=cur->next;
            free(cur);
            return;
        }
        else if(prev==NULL && val==cur->data)
        {
            prev=cur;
            cur=cur->next;
            *head=cur;
            free(prev);
        }
        else
            prev=cur;
    }

    printf("Element not found \n");
}

Linked_List* Recursive_Delete(Linked_List **head, int val)
{
    Linked_List* next;
    if (*head == NULL)
    { // Found the tail
        printf("Element not found \n");
        return NULL;
    }
    else if ((*head)->data == val)
    { // Found one to delete
        next = (*head)->next;
        free(*head);
        return next;
    }
    else
    { // Just keep going
        (*head)->next = Recursive_Delete(&(*head)->next, val);
        return *head;
    }
}

void Reverse(Linked_List **head)
{
    Linked_List *temp,*prev,*cur;
    temp=prev=NULL;

    if((*head)->next==NULL)
        return;

    cur=*head;
    while(cur!=NULL)
    {
        temp=prev;
        prev=cur;
        cur=cur->next;
        prev->next=temp;
    }
    *head=prev;
}

void Display_Reverse(Linked_List *head)
{
    Linked_List *cur=head;

    if(cur==NULL)
        return;
    else
    {
        Display_Reverse(cur->next);
        printf("%d ",cur->data);
    }
}

int Count(Linked_List *head)
{
    Linked_List *cur=head;
    int c=0;

    for(cur=head;cur!=NULL;cur=cur->next)
        c++;
    return c;
}

int Recursive_Count(Linked_List *head)
{
    Linked_List *cur=head;
    static int c=0;

    if(head==NULL)
        return c;
    else
    {
        c++;
        Recursive_Count(cur->next);
    }
}

void Split_Even_Odd(Linked_List *head, Linked_List **head_even, Linked_List **head_odd)
{
    Linked_List *cur;

    for(cur=head;cur!=NULL;cur=cur->next)
    {
        if(cur->data%2==0)
            Insert_Serial(head_even,cur->data);
        else
            Insert_Serial(head_odd,cur->data);
    }

}

void Merge(Linked_List *head1, Linked_List *head2, Linked_List **head)
{
    Linked_List *cur;
    initialization(head);

    for(cur=head1;cur!=NULL;cur=cur->next)
        Insert_Sorted(head,cur->data);
    for(cur=head2;cur!=NULL;cur=cur->next)
        Insert_Sorted(head,cur->data);

}

void Search(Linked_List *head, int val)
{
    Linked_List *cur;
    int c=1;

    for(cur=head;cur!=NULL;cur=cur->next)
    {
        if(val==cur->data)
        {
            printf("Element found at Node number: %d \n",c);
            return;
        }
        c++;
    }
    printf("Element not present in Linked List \n");
}

void Recursive_max(Linked_List *head, int *max)
{
    if(head==NULL)
        return;

    Recursive_max(head->next,max);
    if(head->data>*max)
        *max=head->data;

}

int main()
{
    int ch,n;
    char ch2;
    int max=-9999999;
    Linked_List *ser_l,*sort_l,*even,*odd,*m_ss,*m_oe;

    initialization(&ser_l);
    initialization(&sort_l);
    initialization(&even);
    initialization(&odd);

    while(1)
    {
        printf("**********MENU********** \n");
        printf("1. Insert in Sorted order using Iteration \n");
        printf("2. Insert in Sorted order using Recursion \n");
        printf("3. Insert in Serial order using Iteration \n");
        printf("4. Insert in Serial order using Recursion \n");
        printf("5. Display using Iteration \n");
        printf("6. Display using Recursion \n");
        printf("7. Delete element from Linked List using Iteration \n");
        printf("8. Delete element from Linked List using Recursion \n");
        printf("9. Reverse Linked List using Iteration \n");
        printf("10. Display in Reverse order using Recursion \n");
        printf("11. Count no. of elements using Iteration \n");
        printf("12. Count no. of elements using Recursion \n");
        printf("13. Split Linked List into two containing Odd and Even integers \n");
        printf("14. Merge two Linked List in Sorted order \n");
        printf("15. Search for given integer in Linked List \n");
        printf("16. Search for max element in Linked List using Recursion \n");
        printf("\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter element: \n");
            scanf("%d",&n);
            Insert_Sorted(&sort_l,n);
            break;

        case 2:
            printf("Enter element: \n");
            scanf("%d",&n);
            Recursive_Insert_Sorted(&sort_l,n);
            break;

        case 3:
            printf("Enter element: \n");
            scanf("%d",&n);
            Insert_Serial(&ser_l,n);
            break;

        case 4:
            printf("Enter element: \n");
            scanf("%d",&n);
            Recursive_Insert_Serial(&ser_l,n);
            break;

        case 5:
            printf("Sorted Elements: ");
            Display(sort_l);
            printf("Serial Elements: ");
            Display(ser_l);
            break;

        case 6:
            printf("Sorted Elements: ");
            Recursive_Display(sort_l);
            printf("\n");
            printf("Serial Elements: ");
            Recursive_Display(ser_l);
            printf("\n");
            break;

        case 7:
            printf("Enter element to be deleted: \n");
            scanf("%d",&n);
            printf("In the Sorted Linked List: ");
            Delete(&sort_l,n);
            printf("In the Serial Linked List: ");
            Delete(&ser_l,n);
            break;

        case 8:
            printf("Enter element to be deleted: \n");
            scanf("%d",&n);
            printf("In the Sorted Linked List: ");
            sort_l=Recursive_Delete(&sort_l,n);
            if(sort_l!=NULL)
                printf("%d deleted successfully \n",n);
            printf("In the Serial Linked List: ");
            ser_l=Recursive_Delete(&ser_l,n);
            if(ser_l!=NULL)
                printf("%d deleted successfully \n",n);
            break;

        case 9:
            Reverse(&sort_l);
            printf("Reversed Sorted Linked List: ");
            Display(sort_l);
            printf("\n");
            Reverse(&ser_l);
            printf("Reversed Serial Linked List: ");
            Display(ser_l);
            printf("\n");
            break;

        case 10:
            printf("Reverse Display Sorted Elements: ");
            Display_Reverse(sort_l);
            printf("\n");
            printf("Reverse Display Serial Elements: ");
            Display_Reverse(ser_l);
            printf("\n");

            break;

        case 11:
            printf("Number of elements in Sorted Linked List: %d \n",Count(sort_l));
            printf("Number of elements in Serial Linked List: %d \n",Count(ser_l));
            break;

        case 12:
            printf("Number of elements in Sorted Linked List: %d \n",Recursive_Count(sort_l));
            printf("Number of elements in Serial Linked List: %d \n",Recursive_Count(ser_l));
            break;

        case 13:
            Split_Even_Odd(sort_l,&even,&odd);
            Split_Even_Odd(ser_l,&even,&odd);
            printf("Even integer Linked List: ");
            Display(even);
            printf("Odd integer Linked List: ");
            Display(odd);
            break;

        case 14:
            Merge(sort_l,ser_l,&m_ss);
            printf("Serial and Sorted Merged Linked List: ");
            Display(m_ss);
            Merge(odd,even,&m_oe);
            printf("Odd and Even Merged Linked List: ");
            Display(m_oe);

            break;

        case 15:
            printf("Enter element to be searched: \n");
            scanf("%d",&n);
            printf("In the Sorted Linked List: ");
            Search(sort_l,n);
            printf("In the Serial Linked List: ");
            Search(ser_l,n);
            break;

        case 16:
            Recursive_max(ser_l,&max);
            printf("Max element is: %d \n",max);
            break;


        default:
            printf("Wrong input \n");
        }

        printf("Continue? y/n ");
        fflush(stdin);
        scanf("%c",&ch2);
        if(ch2=='n')
            break;
        else
        {
            printf("\n");
            continue;
        }
    }

    return 0;
}
