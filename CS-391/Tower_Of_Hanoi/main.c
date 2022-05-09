#include <stdio.h>
#include <stdlib.h>


void initialisation (int *);
void Tower_of_Hanoi ( int *, int , char, char, char);

void initialisation (int * step_count)
{
    *step_count=0;
}

void Tower_of_Hanoi (int *step_count, int N, char Source, char Aux, char Target)
{
    if(N>0)
    {
        Tower_of_Hanoi (step_count, (N-1), Source, Target, Aux);
        printf("\n Step No. %d : Transfer Disk %d from %c to %c", ++(*step_count),N,Source,Target);
        Tower_of_Hanoi (step_count, (N-1), Aux, Source, Target);
    }
}
int main()
{
    int n, step_no;
    printf("Enter the no. of disks: ");
    scanf("%d",&n);
    if(n==0)
    {
        printf("No. of disks must be greater than 0");
        exit(1);
    }

    initialisation(&step_no);
    Tower_of_Hanoi(&step_no,n,'S','A','T');

    return 0;
}
