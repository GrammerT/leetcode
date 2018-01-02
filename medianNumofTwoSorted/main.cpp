#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int count ;
        vector<int> v;
        if(m>n)
        {
            count = n;
        }
        else
        {
            count = m;
        }
        int i;
        int j=0;
        for(i=0;i<count;++i)
        {
            while(nums1.at(i)<nums2.at(j))
            {
                v.push_back(nums1.at(i));
            }
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
//    nums2.push_back(3);
    Solution s;
    cout<< s.findMedianSortedArrays(nums1,nums2);
    return 0;
}
