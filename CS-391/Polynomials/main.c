#include <stdio.h>
#include <stdlib.h>

typedef struct Polynomial
{
	int coeff, exp;
	struct Polynomial *next;
}Polynomial;

void Delete(Polynomial **, Polynomial *);
void addnode(Polynomial **, int , int );
void Addition(Polynomial *, Polynomial *, Polynomial **);
void Multiply(Polynomial *, Polynomial *, Polynomial **);
void Display(Polynomial *);

int main()
{
	Polynomial *poly1 = NULL, *poly2 = NULL, *poly3 = NULL,*poly4=NULL;
	int c,e;

	printf("Polynomial 1:\n");
    while(1)
    {
    	printf("Enter coefficient(or 0 to stop): ");
    	scanf("%d", &c);
    	if(c==0)
    		break;
    	printf("Enter exponent: ");
    	scanf("%d", &e);
    	addnode(&poly1,c,e);
    }
    printf("Polynomial 2:\n");
    while(1)
    {
    	printf("Enter coefficient(or 0 to stop): ");
    	scanf("%d", &c);
    	if(c==0)
    		break;
    	printf("Enter exponent: ");
    	scanf("%d", &e);
    	addnode(&poly2,c,e);
    }

    printf("\n");
    printf("1st Polynomial: ");
    Display(poly1);
    printf("2nd Polynomial: ");
    Display(poly2);
    printf("\n");

    Addition(poly1,poly2,&poly3);
    printf("Addition of the two polynomials: ");
    Display(poly3);
    Multiply(poly1,poly2,&poly4);
    printf("Multiplication of the two polynomials: ");
    Display(poly4);

	return 0;
}

void addnode(Polynomial **head, int coeff, int power)
{
    Polynomial *t,*cur,*prev=NULL;

	t=(Polynomial *)malloc(sizeof(Polynomial));
	t->coeff = coeff;
	t->exp = power;

	if(*head==NULL || (*head)->exp<power)
    {
        t->next=*head;
        *head=t;
        return;
    }

    if((*head)->exp==power)
    {
        (*head)->coeff+=coeff;
        if((*head)->coeff==0)
        {
            Polynomial *p=*head;
            Delete(head,p);
        }
        return;
    }

	for(cur=*head;cur->next && (cur->next)->exp>power;cur=cur->next);

    if(cur->next!=NULL && (cur->next)->exp==power)
    {
        (cur->next)->coeff+=coeff;
        if((cur->next)->coeff==0)
            Delete(head,(cur->next));
        return;
    }

    /*for(cur=*head;cur && cur->exp>power;cur=cur->next)
        prev=cur;

    if(prev)
    {
        cur->coeff+=coeff;
        if(cur->coeff==0)
            Delete(head,cur);
        return;
    }*/
    t->next=cur->next;
    cur->next=t;
    return;
}

void Addition(Polynomial *poly1, Polynomial *poly2, Polynomial **poly3)
{
    Polynomial *p1,*p2;

    for(p1=poly1;p1;p1=p1->next)
        addnode(poly3,p1->coeff,p1->exp);
    for(p2=poly2;p2;p2=p2->next)
        addnode(poly3,p2->coeff,p2->exp);
}

void Multiply(Polynomial *poly1, Polynomial *poly2, Polynomial **poly3)
{
    Polynomial *p1,*p2;

    for(p1=poly1; p1 ;p1=p1->next)
    {
        for(p2=poly2; p2 ;p2=p2->next)
        {
            addnode(poly3,p1->coeff*p2->coeff,p1->exp+p2->exp);
        }
    }
}

void Delete(Polynomial **head,Polynomial *node)
{
    Polynomial *cur=*head,*prev=NULL;

    if(node==cur)
    {
        cur=cur->next;
        *head=cur;
        free(node);
    }
    else
    {
        while(cur!=node)
        {
            prev=cur;
            cur=cur->next;
        }
        prev->next=cur->next;
        free(cur);

    }

}

void Display(Polynomial *ptr)
{
    if(ptr==NULL)
    {
        printf("0 \n");
        return;
    }
	while (ptr->next != NULL)
    {
        if(ptr->exp==1)
            printf("%dx",ptr->coeff);
        else
            printf("%dx^%d",ptr->coeff,ptr->exp);
        if(ptr->next!=NULL && ptr->next->coeff>=0)
            printf("+");


		ptr=ptr->next;
	}
	printf("%d \n",ptr->coeff);
}
