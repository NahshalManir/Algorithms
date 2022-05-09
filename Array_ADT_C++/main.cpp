#include <iostream>

using namespace std;

template<class T>

class Array
{
private:
    T *A;
    int size;
    int length;
    void swap(int *x,int *y);
public:
    Array()
    {
        size=10;
        length=0;
        A=new T[size];
    }
    Array(int sz)
    {
        size=sz;
        length=0;
        A=new T[size];
    }
    ~Array()
    {
        delete []A;
    }
    void Display();
    void Insert(int index, T x);
    void Append(T x);
    T Delete(int index);

};

template<class T>
void Array<T>::Display()
{
    int i;
    for(i=0;i<length;i++)
        cout << A[i] << " ";
        cout<<endl;
}

template<class T>
void Array<T>::Insert(int index, T x)
{
    int i;
    if(index>=0 && index<=length)
    {
        for(i=length;i>=index;i--)
            A[i]=A[i-1];
        A[index]=x;
        length++;
    }
}

template<class T>
void Array<T>::Append(T x)
{
    if(length<size)
        A[length++]=x;
}

template<class T>
T Array<T>::Delete(int index)
{
    int i;
    T x;
    if(index>=0 && index<length)
    {
        x=A[index];
        for(i=index;i<length-1;i++)
            A[i]=A[i+1];
        length--;
    }
    return(x);
}

int main()
{
    Array<string> arr(10);

    arr.Insert(0,"Hello");
    arr.Insert(1,"I");
    arr.Insert(2,"Am");
    arr.Display();
    arr.Append("Okay");
    arr.Display();

    return(0);
}












