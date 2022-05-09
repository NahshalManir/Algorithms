#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int A[10];
    int n;
};

void Set(struct Matrix *m,int i, int j,int x)
{
    if(i==j)
        m->A[i-1]=x;
}

int Get(struct Matrix m,int i,int j)
{
    if(i==j)
        return m.A[i-1];
    else
        return 0;
}

void Display(struct Matrix m)
{
    int i;
    for(i=0;i<m.n;i++)
        printf("%d ",m.A[i]);
}

int main()
{
    struct Matrix m;
    m.n=4;

    Set(&m,1,1,2);
    Set(&m,2,2,4);
    Set(&m,3,3,6);
    Set(&m,4,4,8);
    printf("%d\n",Get(m,3,3));
    Display(m);
}
