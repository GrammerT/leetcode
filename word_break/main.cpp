#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordBreak(string s,
                   vector<string>& wordDict) {
        int startIndex = 0;
        int s_size = 0;
        int size = s.size();
        while(s_size<s.size()&&startIndex<s.size())
        {
            bool isSub = false;
            for(int i=startIndex+1;i<=s.size();++i)
            {
                string sbuStr = s.substr(startIndex,i-startIndex);
                vector<string>::iterator iter =
                        find(wordDict.begin(),wordDict.end(),sbuStr);
                if(iter!=wordDict.end())
                {
                    s_size+=(i-startIndex);
                    startIndex=i;
                    isSub = true;
                    break;
                }
            }
            if(!isSub)
            {
                startIndex++;
            }
        }
        if(s_size==s.size())
            return true;
        return false;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    string str= "aaaaaaa";
    vector<string> wordDict;
    wordDict.push_back("aaaa");
    wordDict.push_back("aaa");
    s.wordBreak(str,wordDict);
    return 0;
}
