#include <iostream>

using namespace std;

    int main()
    {
        int nums[5], target, flag=0;

        cout << "Enter target: " << endl;
        cin >> target;

        cout << "Enter numbers: " << endl;
        for(int i=0; i<5; i++)
        {
            cin >> nums[i];
        }

        for(int i=0; i<5; i++)
        {
            for(int j=i+1; j<5; j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    cout << i << " " << j << endl;
                    flag=1;
                    break;
                }
            }
        }

        if(flag==1)
            return(0);
        else
        {
            cout << "No answer! " << endl;
            return(0);
        }
    }
