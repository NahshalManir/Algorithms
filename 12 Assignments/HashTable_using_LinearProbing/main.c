#include <stdio.h>
#include <stdlib.h>

int hasht(int key, int size)
{
 int i ;
 i = key%size ;
 return i;
}

//-------LINEAR PROBING-------
int rehashl(int key, int size)
{
 int i ;
 i = (key+1)%size ;
 return i ;
}

int main()
{
    int key,arr[20],hash[20],i,n,k,size ;
    printf ("Enter the size of the hash table:  ");
    scanf ("%d",&size);

    printf ("\nEnter the number of elements: ");
    scanf ("%d",&n);

    for (i=0;i<size;i++)
 hash[i]=-1 ;

    printf ("Enter Elements: ");
    for (i=0;i<n;i++)
    {
 scanf("%d",&arr[i]);
    }

     for (i=0;i<size;i++)
     hash[i]=-1 ;

     for(k=0;k<n;k++)
     {
  key=arr[k] ;
  i = hasht(key,size);
  while (hash[i]!=-1)
  {
      i = rehashl(i,size);
  }
  hash[i]=key ;
     }
     printf("\nThe elements in the array are: ");
     for (i=0;i<size;i++)
     {
  printf("\n  Element at position %d: %d",i,hash[i]);
     }

    return 0;
}
