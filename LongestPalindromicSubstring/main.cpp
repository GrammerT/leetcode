#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        vector<string> v_valid;
        string longestSubstring="";
        map<char,int> chartoindex;
        for(int i=0;i<s.size();++i)
        {
            if(chartoindex.count(s.at(i)))
            {
                int startpos = chartoindex[s.at(i)];
                int distance = i-startpos;
                if(longestSubstring.size()<distance+1)
                {
                    longestSubstring=s.substr(startpos,distance+1);
                }
            }
            else
            {
                chartoindex[s.at(i)]=i;
            }
        }
        return longestSubstring;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    string str="babaaaab";
    cout<<s.longestPalindrome(str)<<endl;
    return 0;
}
