#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        int start = 0;
        int end = 0;
        int maxSum = INT_MIN ;
        int frontSum = 0;
//        vector<vector<int>> sumArray(nums.size(),vector<int>(nums.size(),0));
        for(int i=0;i<nums.size();++i)
        {
            frontSum=nums[i];
            if(maxSum<frontSum)
            {
                maxSum = frontSum;
            }
            for(int j=i+1;j<nums.size();++j)
            {
                frontSum=nums[j]+frontSum;
                if(maxSum<frontSum)
                {
                    start = i;
                    end = j;
                    maxSum = frontSum;
                }
            }
        }
        return maxSum;
    }
};

int main(int argc, char *argv[])
{
    int a[9]={-2,1,-3,4,-1,2,1,-5,4};
    vector<int> v;
    for(int i=0;i<9;++i)
    {
        v.push_back(a[i]);
    }
    Solution s;
    s.maxSubArray(v);
    return 0;
}
