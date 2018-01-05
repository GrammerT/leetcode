#include <iostream>
#include "binarysearch.h"
using namespace std;

int main(int argc, char *argv[])
{
    BinarySearch bs;
    cout<<BinarySearch::twoBinarySearch(bs.data,bs.data.size(),64)<<endl;
    cout<<BinarySearch::twoBinarySearch(bs.data,bs.data.size(),88)<<endl;
    return 0;
}
