#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int row;
    int col;
    int val;
    struct Node *next;
}*first=NULL;

void create(int A[5][6])
{
    int i,j,flag=0;
    struct Node *t,*p,*last;

    for(i=0;i<5;i++)
    {
        for(j=0;j<6;j++)
        {
            if(A[i][j]!=0)
            {
                if(flag==0)
                {
                    first=(struct Node*)malloc(sizeof(struct Node));;
                    first->row=i;
                    first->col=j;
                    first->val=A[i][j];
                    flag=1;
                    first->next==NULL;
                    last=first;
                }
                else
                {
                    t=(struct Node*)malloc(sizeof(struct Node));
                    t->val=A[i][j];
                    t->row=i;
                    t->col=j;
                    t->next=NULL;
                    last->next=t;
                    last=t;
                }
            }
        }
    }

}

void Display(struct Node *p)
{
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<6;j++)
        {
            if(p==NULL)
                printf("0 ");
            else if(i==p->row && j==p->col)
            {
                printf("%d ",p->val);
                p=p->next;
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    int A[5][6]={{0,0,0,0,8,0},
                 {0,0,0,7,0,0},
                 {5,0,0,0,9,0},
                 {0,0,0,0,0,3},
                 {6,0,0,4,0,0}};
    create(A);
    Display(first);

    return 0;

}
