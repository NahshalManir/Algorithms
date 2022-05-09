#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int>& nums, int k) {
        if(k==nums.size())
            return;

        int i,n=nums.size(),p=k,temp,temp2;
        if(p>n)
            p=k/n;
        temp=nums[p];
        nums[p]=nums[0];
        for(i=0;i<n-1;i++)
        {
            p=p+k;
            if(p>n)
                p=k/n;
            temp2=temp;
            temp=nums[p];
            nums[p]=temp2;
        }
}

int main()
{
    int i;
    vector<int> A={1,2,3,4,5,6,7};
    rotate(A,3);

    int n=A.size();
    for(i=0;i<n;i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
