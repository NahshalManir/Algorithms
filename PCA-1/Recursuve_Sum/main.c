
typedef struct Linked_List
{
    int data;
    struct Linked_List *next;
}Linked_List;


int Recursive_Sum(Linked_List *head)
{
    Linked_List *cur=head;
    static int sum=0;

    if(head==NULL)
        return sum;
    else
    {
        sum=sum+cur->data;
        return Recursive_Sum(cur->next);
    }
}
