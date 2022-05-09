#include <iostream>

using namespace std;

int main()
{
   const int num=85453;

   int r, rev=0;
   while(num>0)
   {
       r=num%10;
       rev=rev*10+r;
       num=num/10;
   }

   cout<<"Original number: " << num << endl;
   cout << "Reversed number: " << rev << endl;

   return(0);
}
