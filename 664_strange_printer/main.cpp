#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        if(s.size()==0)
            return 0;
        if(s.size()==1)
            return 1;
        char first = s[0];
        int count = 1;
        for(int i=1;i<s.size();++i)
        {
            if(first==s.at(i))
            {
                continue;
            }
            else if(s.at(i)==s.at(i-1))
            {
                continue;
            }
            else
            {
                count++;
            }
        }
        return count;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout<<s.strangePrinter("abcabc");
    return 0;
}
