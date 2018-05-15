#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        int p[2]={0,1};
        vector<int> charNum;
        for(int i=0;i<=num;++i)
        {
            int chars=0;
            int tmp = i;
            while(tmp>0)
            {
                chars+=p[tmp%2];
                tmp>>=1;
            }
            charNum.push_back(chars);
        }
        return charNum;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    s.countBits(5);
    return 0;
}
