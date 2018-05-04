#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
static auto static_lambda = [] () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    return 0;
}();
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
        {
            return nums[0];
        }
        if(nums.size()==2)
        {
            return nums[0]>nums[1]?nums[0]:nums[1];
        }
        vector<int> reseve(nums.size());
        for(int i=0;i<reseve.size();++i)
        {
            reseve[i]=-1;
        }
        reseve[0]=nums[0];
        reseve[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();++i)
        {
            reseve[i] = max((reseve[i-2]+nums[i]),reseve[i-1]);
        }
        return reseve[reseve.size()-1];
    }
};

int main(int argc, char *argv[])
{
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
//    v.push_back(9);
    Solution s;
    s.rob(v);
    return 0;
}
