#include <iostream>

using namespace std;

int main()
{
    int l[10],i,j,temp=0;
    cout << "Enter numbers: " << endl;
    for(i=0; i<10; i++)
    {
        cin >> l[i];
    }
    for(i=0; i<9; i++)
    {
        int pos=i;
        for(j=i+1; j<10; j++)
        {
            if(l[j]<l[pos])
            {
                pos=j;
            }
            temp=l[i];
            l[i]=l[pos];
            l[pos]=temp;
        }
    }
    for(i=0; i<10; i++)
    {
        cout << l[i] << " ";
    }
    return (0);
}
