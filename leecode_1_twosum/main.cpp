#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;

        for(int i=0;i<nums.size();++i)
        {
            for(int j=i+1;j<nums.size();++j)
            {
                if(nums[i]+nums[j]==target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    return  result;
                }
            }
        }
        return  result;
    }
};

//! optimization
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> order_map;
        for(int i=0;i<nums.size();++i)
        {
            if(order_map.count(target-nums[i]))
            {
                return {order_map[target-nums[i]],i};
            }
            order_map[nums[i]]=i;
        }
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(6);
    Solution1 s;
    vector<int> re = s.twoSum(nums,9);
    if(re.size()>0)
    {
        cout<<re[0]<<" "<<re[1];
    }
    return 0;
}
