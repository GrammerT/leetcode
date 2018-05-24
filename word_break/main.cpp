#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordBreak(string s,
                   vector<string>& wordDict) {
        vector<int> vb(s.size(),-1);
        return isMatch(s,wordDict,vb);
    }
    bool isMatch(string s,vector<string>& wordDict,vector<int>&vb)
    {
        vector<string>::iterator iter = find(wordDict.begin(),wordDict.end(),s);
        if(iter!=wordDict.end())
            return true;
        for(int i=1;i<s.size();++i)
        {
            string substr = s.substr(0,i);
            vector<string>::iterator iter = find(wordDict.begin(),wordDict.end(),substr);
            if(iter!=wordDict.end())
            {
                bool isWord;
                if(vb[i]!=-1)
                {
                    isWord=vb[i];
                }
                else
                {
                    isWord = isMatch(s.substr(i,s.size()-1),wordDict,vb);
                    vb[i]=isWord;
                }
                if(isWord)
                    return true;
            }
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    string str= "aaaaaaa";
    string str1= "abcdefghi";
    string sss=str1.substr(0,0);
    vector<string> wordDict;
    wordDict.push_back("aaaa");
    wordDict.push_back("aaa");
    s.wordBreak(str,wordDict);
    return 0;
}
