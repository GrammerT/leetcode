#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i=0;i<nums.size();++i)
        {
            if(result.size()>0)
                break;
            if(nums.at(i)>=target)
                continue;
            for(int j=nums.size()-1;j>i;--j)
            {
                if(nums[j]+nums[i]==target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
        }
        return result;
    }
};

//! other

class Solution1
{
public:

    std::vector<int> twoSum(std::vector<int> &numbers,  //  the array of the number
                            int target) //  the sum of the two num
    {
        std::unordered_map<int, int> mp;

        std::vector<int> ans;

        //  用哈希表来做
        for(int i = 0; i < numbers.size(); i ++)    //  对于数组中的每个数据
        {
            //  判断target - numbers[i]在不在
            if(mp.count(target - numbers[i]))   //  如果在里面
            {
                //  那么numbers中就存在两个数和为target
                ans.push_back(mp[target - numbers[i]] + 1);
                ans.push_back(i + 1);
                break;
            }

            if(mp.count(numbers[i]) != 1)
            {
                mp[numbers[i]] = i;
            }
        }
        return ans;
    }
};
