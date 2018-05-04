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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> nums;
        nums.insert(nums.begin(),nums1.begin(),nums1.end());
        nums.insert(nums.end(),nums2.begin(),nums2.end());
        sort(nums.begin(),nums.end());
        return median(nums);
    }
    double median(vector<int> nums)
    {
        if(nums.size()%2==0)
        {
            return (nums[nums.size()/2]+nums[nums.size()/2-1])/2.0;
        }
        return nums[nums.size()/2];
    }
};

//! optimazed.
class Solution1 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int pre = 0, cur = 0, index = 0;
        int size = nums1.size() + nums2.size();

        auto it1 = nums1.begin();
        auto end1 = nums1.end();
        auto it2 = nums2.begin();
        auto end2 = nums2.end();

        do {
            if (it1 == end1 && it2 == end2) {
                break;
            }


            if (it1 == end1) {
                for (; it2 != end2; ++it2) {
                    ++index;
                    pre = cur;
                    cur = *it2;

                    if (size % 2 == 0 && index == size / 2 + 1) {
                        return (pre + cur) / 2.0;
                    }
                    else if (size % 2 == 1 && index == size / 2 + 1) {
                        return cur;
                    }

                }
            }
            else if (it2 == end2) {
                for (; it1 != end1; ++it1) {
                    ++index;
                    pre = cur;
                    cur = *it1;

                    if (size % 2 == 0 && index == size / 2 + 1) {
                        return (pre + cur) / 2.0;
                    }
                    else if (size % 2 == 1 && index == size / 2 + 1) {
                        return cur;
                    }
                }
            }
            else {
                ++index;
                pre = cur;
                if (*it1 < *it2)
                {
                    cur = *it1;
                    ++it1;
                }
                else
                {
                    cur = *it2;
                    ++it2;
                }
                if (size % 2 == 0 && index == size / 2 + 1) {
                    return (pre + cur) / 2.0;
                }
                else if (size % 2 == 1 && index == size / 2 + 1) {
                    return cur;
                }
            }
        } while (true);
        return 0.0;
    }
};


int main(int argc, char *argv[])
{

    return 0;
}
