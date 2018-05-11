#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        char p[2]={'0','1'};
        vector<int> charNum;
        for(int i=0;i<=num;++i)
        {
            vector<char> chars;
            int tmp = i;
            while(tmp>0)
            {
                chars.push_back(p[tmp%2]);
                tmp=tmp/2;
            }
            int count =0;
            for(int j=0;j<chars.size();++j)
            {
                if('1'==chars[j])
                    count++;
            }
            charNum.push_back(count);
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
