#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define INFINITE 9999999
#define N 9

typedef struct
{
    int data[MAX];
    int top;
}Stack;

//Prototype declaration
void initializeStack (Stack *);
void push (Stack *, int );
int pop (Stack *);
int peek (Stack);

void initializeStack(Stack *stk)
{
    stk->top=-1;
}

void push(Stack *stk, int val)
{
    if(stk->top!=MAX-1)
        stk->data[++(stk->top)]=val;
    else
        printf("Stack Overflow \n");
}

int pop(Stack *stk)
{
    if(stk->top!=-1)
        return stk->data[(stk->top)--];
    else
    {
        printf("Stack Underflow \n");
        return -999999;
    }
}

int peek(Stack stk)
{
    if(stk.top!=-1)
        return stk.data[stk.top];
    else
    {
        printf("Stack Underflow \n");
        exit(1);
    }
}

void reverseGraphEdges(int G[N][N])
{
    int i,j,temp;

    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
        {
            temp=G[i][j];
            G[i][j]=G[j][i];
            G[j][i]=temp;
        }
}

void DFSLoop(int G[N][N])
{
    Stack stk;
    initializeStack(&stk);
    int i,j,t=0,flag=1;
    int explored[N];
    int f[N];

    //reverseGraphEdges(G);

    for(i=0;i<N;i++)
        explored[i]=0;

    for(i=N-1;i>=0;i--)
    {
        if(explored[i]==0)
        {
            push(&stk,i);
            while(stk.top!=-1)
            {
                flag=0;
                i=peek(stk);
                explored[i]=1;
                for (j=0; j<N; j++)
                    if(G[i][j]!=0 && explored[j]==0)
                    {
                        push(&stk, j);
                        flag=1;
                    }
                if(flag!=1)
                {
                    i=pop(&stk);
                    printf("%d ",i+1);
                    f[i]=++t;
                }
            }
        }
    }

    printf("\n");
    for(i=0;i<N;i++)
        printf("%d ",f[i]);
    printf("\n");

}

int main()
{
    int G[N][N]=    {{0,0,0,0,0,0,1,0,0},
                    {0,0,0,0,1,0,0,0,0},
                    {0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,1,0},
                    {0,0,0,0,0,0,0,1,0},
                    {0,0,0,0,0,0,0,0,1},
                    {0,1,0,0,0,0,0,0,0},
                    {0,0,0,0,0,1,0,0,0}};
    DFSLoop(G);

    return 0;
}
