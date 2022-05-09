#include <stdio.h>
#define MAX 100

struct student
{
    char name[MAX];
    int roll;
};

void display(struct student x)
{
    printf("%s %d",x.name,x.roll);
    printf("\n");
}

struct student create()
{
    struct student temp;
    printf("Enter name of student: ");
    scanf("%[^\n]",temp.name);
    printf("Enter Roll No. of student: ");
    scanf("%d",&temp.roll);
    return temp;

}

int main()
{
    struct student s1;
    s1=create();
    display(s1);
    return 0;
}
