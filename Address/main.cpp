#include <iostream>

using namespace std;


int main()
{
    int nums[5]={10,15,35,24,46};
    cout << *nums << endl;

    int *numsptr=nums;
    cout << numsptr << endl;
    return(0);
}

