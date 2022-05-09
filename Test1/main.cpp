#include<climits>
#include<iostream>
#include<vector>
#include<cmath>
#include<stdlib.h>
#include<string>

using namespace std;

struct Array
{
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    for(i=0;i<arr.length;i++)
        printf("%d ",arr.A[i]);
}

void Delete(struct Array *arr,int index)
{
    if(index>=0 && index<arr->length-1)
    {
        for(int i=index;i<arr->length-1;i++)
            arr->A[i]=arr->A[i+1];
        arr->length--;
    }
}

int Get(struct Array arr,int index)
{
    if(index>=0 && index<arr.length)
        return(arr.A[index]);
    else
        return (-1);
}

void Reverse(struct Array *arr)
{
    int i,j,temp;
    for(i=0,j=arr->length-1;i<=j;i++,j--)
    {
        temp=arr->A[i];
        arr->A[i]=arr->A[j];
        arr->A[j]=temp;
    }
}

void Set(struct Array *arr,int index,int x)
{
    if(index>=0 && index<arr->length)
        arr->A[index]=x;
}

int Max(struct Array arr)
{
    int i,maximum=arr.A[0];
    for(i=1;i<arr.length;i++)
    {
        if(arr.A[i]>maximum)
            maximum=arr.A[i];
    }
    return(maximum);
}

int Min(struct Array arr)
{
    int i,minimum=arr.A[0];
    for(i=1;i<arr.length;i++)
    {
        if(arr.A[i]<minimum)
            minimum=arr.A[i];
    }
    return(minimum);
}

void NegLeft(struct Array *arr)
{
    int i=0,j=arr->length-1,temp;
    while(i<j)
    {
        while(arr->A[i]<0)
            i++;
        while(arr->A[j]>=0)
            j--;
        if(i<j)
        {
            temp=arr->A[i];
            arr->A[i]=arr->A[j];
            arr->A[j]=temp;
        }
    }
}

void InsertSorted(struct Array *arr,int x)
{
    int i=arr->length-1;
    while(arr->A[i]>x)
    {
        arr->A[i]=arr->A[i-1];
        i--;
    }
    arr->A[i+1]=x;
}

struct Array* Merge(struct Array *arr1, struct Array *arr2)
{
    int i=0,j=0,k=0;
    struct Array *arr3=(struct Array*)malloc(sizeof(struct Array));
    arr3->size=arr1->size+arr2->size;

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else
            arr3->A[k++]=arr2->A[j++];
    }
    for( ;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    for( ;j<arr2->length;j++)
        arr3->A[k++]=arr2->A[j];
        arr3->length=arr1->length+arr2->length;
        arr3->size=10;

    return(arr3);
}


struct Array* Union(struct Array *arr1,struct Array *arr2)
{
    int i=0,j=0,k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i])
            arr3->A[k++]=arr2->A[j++];
        else
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    for( ;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    for( ;j<arr2->length;j++)
        arr3->A[k++]=arr2->A[j];

    arr3->size=10;
    arr3->length=k;

    return(arr3);


}

struct Array* Difference(struct Array *arr1,struct Array *arr2)
{
    int i=0,j=0,k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for( ;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];


    arr3->size=10;
    arr3->length=k;

    return(arr3);


}

struct Array* Intersection(struct Array *arr1,struct Array *arr2)
{
    int i=0,j=0,k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            i++;
        else if(arr2->A[j]<arr1->A[i])
            j++;
        else
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }

    arr3->size=10;
    arr3->length=k;

    return(arr3);


}

int main()
{
    struct Array arr1={{1,2,2,1},10,4};
    struct Array arr2={{2,2},10,2};
    struct Array *arr3;
    arr3=Intersection(&arr1,&arr2);
    Display(*arr3);


    /*struct Array arr={{0,2,4,6,8,10},10,6};
    InsertSorted(&arr,5);
    Display(arr);*/



    return 0;
}
