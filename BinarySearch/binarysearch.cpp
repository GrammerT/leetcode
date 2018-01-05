#include "binarysearch.h"
#include <iostream>

using namespace std;

BinarySearch::BinarySearch()
{
    //1
//    data.push_back(1);
//    data.push_back(2);
//    data.push_back(4);
//    data.push_back(5);
//    data.push_back(34);
//    data.push_back(64);
//    data.push_back(66);
//    data.push_back(67);
//    data.push_back(87);
//    data.push_back(98);
//    data.push_back(99);
//    data.push_back(788);
    //end 1
    //2
    data.push_back(1);
    data.push_back(2);
    data.push_back(4);
    data.push_back(5);
    data.push_back(64);
    data.push_back(64);
    data.push_back(64);
    data.push_back(67);
    data.push_back(98);
    data.push_back(98);
    data.push_back(99);
    data.push_back(788);
    //end 1
}

int BinarySearch::binarySearch(std::vector<int> &nums, int n, int target)
{
    int low = 0;
    int high = n-1;
    while(low<=high)
    {
        int mediau = low+((high-low)>>1);//! 切记移位运算+括号
        if(nums[mediau]==target)
            return mediau;
        else if(nums[mediau]>target)
        {
            high = mediau-1;
        }
        else
        {
            low = mediau+1;
        }
    }
    return -1;
}

int BinarySearch::twoBinarySearch(std::vector<int> &nums, int n, int target)
{
    int low = 0;
    int high = n-1;
    int index=-1;
    while(low<high)
    {
        int mediau = low+((high-low)>>1);//! 切记移位运算+括号
        if(nums[mediau]<target)
        {
            low = mediau+1;
        }
        else
        {
            high=mediau;
        }
    }
    if(nums[low]==target)
        return low;
    else
    {
        return -1;
    }
}
