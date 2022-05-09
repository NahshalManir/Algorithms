#include<stdio.h>
#include<stdlib.h>
#define INFINITE 10000
#define EMPTY_ERROR -9999

typedef struct
{
    int n;
    int *V;
    int **wt;
}GRAPH;

typedef struct
{
    int top;
    int *vertex;
}STACK;

typedef struct
{
    int front, rear;
    int *vertex;
}QUEUE;

// Prototype Declaration
void input_graph(GRAPH *);
void initialisation_stack(STACK *, int);
void initialisation_queue(QUEUE *, int );
void push(STACK *, int );
void insert_q(QUEUE *, int );
int pop(STACK *);
int delete_q(QUEUE *);
void DFS(GRAPH);
void BFS(GRAPH);
void free_graph (GRAPH *);

void input_graph(GRAPH *aG)
{
    int i,j;
    char ans;
    printf("\n Enter the no. of vertices: ");
    scanf("%d",&aG->n);
    aG->V=(int *)malloc(sizeof(int)*aG->n);
    for(i=0;i<aG->n;i++)
        aG->V[i]=i;
    aG->wt=(int **)malloc(sizeof(int *)*aG->n);
    for(i=0; i<aG->n; i++)
        aG->wt[i]=(int *)malloc(sizeof(int)*aG->n);
    for(i=0; i<aG->n; i++)
        for(j=0; j<aG->n; j++)
        {
            printf("\n Is any edge between %d and %d? Answer (Y/N):",i,j);
            fflush(stdin);
            scanf("%c",&ans);
            if(ans=='y'||ans=='Y')
            {
                printf("\n Enter edge cost between %d and %d :",i,j);
                scanf("%d",&aG->wt[i][j]);
            }
            else if(i==j)
                aG->wt[i][j]=0;
            else
                aG->wt[i][j]=INFINITE;
        }
}


void initialisation_stack(STACK *s, int stack_size)
{
    s->top=-1;
    s->vertex=(int *)malloc(sizeof(int)*stack_size);
}

void initialisation_queue(QUEUE *q, int queue_size)
{
    q->front=-1;
    q->rear=-1;
    q->vertex=(int *)malloc(sizeof(int)*queue_size);
}

void push(STACK *s, int v)
{
    s->vertex[++(s->top)]=v;
}

void insert_q(QUEUE *q, int v)
{
    q->vertex[++(q->rear)]=v;
}


int pop(STACK *s)
{
    if(s->top==-1)
    {
        printf("\n Empty stack...");
        return EMPTY_ERROR;
    }
    return s->vertex[(s->top)--];
}

int delete_q(QUEUE *q)
{
    if(q->front==q->rear)
    {
       printf("\n Empty queue...");
       q->front=-1;
       q->rear=-1;
       return EMPTY_ERROR;
    }
    else
       return q->vertex[++(q->front)];
}


void DFS(GRAPH G)
{
    STACK stk;
    int *visited;
    int i, p;
    int start;
    printf("\n");
    initialisation_stack(&stk, G.n);
    visited = (int *)malloc(sizeof(int)*G.n);
    for(i=0;i<G.n;i++)
        visited[i]=0;
    printf("Enter starting vertex for DFS (0-%d): ",G.n-1);
    scanf("%d",&start);
    visited[start]=1;
    push(&stk,start);
    printf("DFS:  ");
    while(stk.top!=-1)
    {
        p=pop(&stk);
        printf("%d  ",G.V[p]);
        for (i=0; i<G.n; i++)
            if(G.wt[p][i]!=0 && G.wt[p][i]!=INFINITE && visited[i]==0)
            {
                push(&stk, i);
                visited[i]=1;
            }
    }
    free(visited);
    printf("\n");
}


void BFS(GRAPH G)
{
    QUEUE queue;
    int *visited;
    int i, p;
    int start;
    printf("\n");
    initialisation_queue(&queue, G.n);
    visited=(int *)malloc(sizeof(int)*G.n);
    for(i=0; i<G.n; i++)
        visited[i]=0;
    printf("Enter starting vertex for BFS (0-%d): ",G.n-1);
    scanf("%d",&start);
    visited[start]=1;
    insert_q(&queue,start);
    printf("BFS:  ");
    while(queue.front != queue.rear)
    {
        p=delete_q(&queue);
        printf("%d  ", G.V[p]);
        for (i=0; i<G.n; i++)
            if(G.wt[p][i]!=0 && G.wt[p][i]!=INFINITE && visited[i]==0)
            {
                insert_q(&queue,i);
                visited[i]=1;
            }

    }
    free(visited);
    printf("\n");
}


void free_graph (GRAPH *G)
{
    int i;

    free(G->V);
    for(i=0; i<G->n; i++)
        free(G->wt[i]);
    free(G->wt);
}


int main()
{
    GRAPH G;
    input_graph(&G);
    DFS(G);
    BFS(G);
    free_graph(&G);

    return 0;
}
