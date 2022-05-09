#include <stdio.h>
#include<stdlib.h>
#define EMPTY -99999

void insert(int h[], int size)
{

    int key,index,i,flag=0,hkey;
    printf("\nEnter a value to insert into hash table: ");
    scanf("%d",&key);
    hkey=key%size;
    for(i=0;i<size;i++)
    {
        index=(hkey+i)%size;

        if(h[index] == EMPTY)
        {
            h[index]=key;
            break;
        }
    }
    if(i==size)
    printf("\nEement cannot be inserted\n");
}

void search(int h[], int size)
{
    int key,index,i,flag=0,hkey;
    printf("\nEnter search element\n");
    scanf("%d",&key);
    hkey=key%size;
    for(i=0;i<size; i++)
    {
        index=(hkey+i)%size;
        if(h[index]==key)
        {
        printf("Value is found at index %d",index);
        break;
        }
    }
    if(i==size)
        printf("\n Value is not found\n");
}

void display(int h[], int size)
{
    int i;

  printf("\nElements in the hash table are \n");
  for(i=0;i< size; i++)
    printf("\nAt index %d \t value =  %d",i,h[i]);

}
int main()
{
    int i,n,opt;
    printf("Enter size of Hash table: ");
    scanf("%d",&n);
    int h[n];
    for(i=0;i<n;i++)
        h[i]=EMPTY;
    while(1)
    {
        printf("\nPress 1. Insert\t 2. Display \t3. Search \t4.Exit \n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                insert(h,n);
                break;
            case 2:
                display(h,n);
                break;
            case 3:
                search(h,n);
                break;
            case 4:exit(0);

            default:
                printf("Wrong choice\n");
        }
    }
}
