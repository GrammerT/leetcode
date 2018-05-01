#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> v;
        for(int i=0;i<nums.size();++i)
        {
            auto iter = find(nums.begin(),nums.end(),i+1);
            if(iter==nums.end())
            {
                v.push_back(i+1);
            }
        }
        return v;
    }
};


class Solution1 {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> v;
        for(int i=0;i<nums.size();++i)
        {
            int index = abs(nums[i])-1;
            nums[index]=nums[index]>0?-nums[index]:nums[index];
        }
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]>0)
            {
                v.push_back(i+1);
            }
        }
        return v;
    }
};

int main(int argc, char *argv[])
{
    Solution1 s;
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(3);
    v.push_back(3);
    v.push_back(5);
    s.findDisappearedNumbers(v);
    return 0;
}
