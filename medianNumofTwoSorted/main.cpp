#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        if(nums1.size()==0)
            return meofArray(nums2);
        if(nums2.size()==0)
            return meofArray(nums1);
        int mid = (nums1.size()+nums2.size())/2;
        bool isJ = (nums1.size()+nums2.size())%2;
        vector<int> nums;
        int first = 0;
        int second = 0;
        int count= 0;
        while(nums.size()<=(mid+1))
        {
            if(first<=nums1.size()-1&&second<=nums2.size()-1)
            {
                if(nums1[first]<nums2[second])
                {
                    nums.push_back(nums1[first]);
                    first++;
                }
                else
                {
                    nums.push_back(nums2[second]);
                    second++;
                }
            }
            else if(first>nums1.size()-1)
            {
                nums.push_back(nums2[second]);
                second++;
            }
            else {
                nums.push_back(nums1[first]);
                first++;
            }
        }
        if(isJ)
        {
            return nums[mid];
        }
        else
        {
            return (nums[mid]+nums[mid-1])/2.0;
        }
    }
    double meofArray(vector<int> nums)
    {
        if(nums.size()%2)
        {
            return nums[nums.size()/2];
        }
        else
        {
            return ((nums[nums.size()/2-1]+nums[nums.size()/2])/2.0);
        }
    }

};

int main(int argc, char *argv[])
{
    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(3);
    vector<int> nums2;
    nums2.push_back(2);
    nums2.push_back(4);
    Solution s;
    cout<< s.findMedianSortedArrays(nums1,nums2)<<endl;
    return 0;
}
