#include<climits>
#include<iostream>

using namespace std;

int trailingZeroes(int n)
    {
        int fac_5=0,k=0;
        for(int i=1;i<=n;i++)
        {
            k=i;
            while(k%5==0)
            {
                k=k/5;
                fac_5++;
            }
        }
        cout << fac_5 << endl;;
        return(0);

    }

int main()
{
    cout << trailingZeroes(30);
    return(0);
}
