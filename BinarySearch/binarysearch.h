#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <vector>

class BinarySearch
{
public:
    BinarySearch();
    //! 1. 给定一个有序（非降序）数组A，求任意一个i使得A[i]等于target，不存在则返回-1
    static int binarySearch(std::vector<int> &nums,int n,int target);
    //! 2. 给定一个有序（非降序）数组A，可含有重复元素，求最小的i使得A[i]等于target，不存在则返回-1
    static int twoBinarySearch(std::vector<int> &nums,int n,int target);
public:
    std::vector<int> data;

};

#endif // BINARYSEARCH_H
