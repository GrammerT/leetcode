#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

//! will limit time. don't AC
class Solution {
public:
    string longestPalindrome(string s) {
        unordered_map<char,vector<int>> chartoindexs;
        string longestSubStr="";
        for(int i=0;i<s.size();++i)
        {
            chartoindexs[s[i]].push_back(i);
        }
        for(auto &iter:chartoindexs)
        {
            vector<int> indexs = iter.second;
            for(int i=0;i<indexs.size();++i)
            {
                int begin=indexs.at(i);
                if(indexs.size()==1)
                {
                    string sub(s,begin,1);
                    if(sub.size()>longestSubStr.size())
                    {
                        longestSubStr=sub;
                    }
                    continue;
                }
                for(int j=i+1;j<indexs.size();++j)
                {
                    int end = indexs.at(j);
                    int left,right;
                    if((begin+end)%2==0)
                    {
                        left = (begin+end)/2-1;
                        right = (begin+end)/2+1;
                    }
                    else
                    {
                        left = (begin+end)/2;
                        right = left+1;
                    }
                    for(int k=0;k<=(right+left)/2;++k)
                    {
                        if(s[left]==s[right])
                        {
                            string substr(s,left,right-left+1);
                            if(substr.size()>longestSubStr.size())
                            {
                                longestSubStr=substr;
                            }
                        }
                        else
                        {
                            break;
                        }
                        left-=1;
                        right+=1;
                        if(left<0)
                            break;
                    }
                }
            }
        }
        return longestSubStr;
    }
};


//! optimazation 1
//! use dp method
class Solution1 {
public:
    string longestPalindrome(string s) {
        int strSize = s.size();
        bool dp[1000][1000] ;
        for(int i=0;i<strSize;++i)
            for(int j=0;j<strSize;++j)
                dp[i][j]=false;
        int max_length=-1; //! record sub string's length
        int start;          //! record sub string's point
        for(int i=0;i<strSize;++i)
        {
            for(int j=0;j<=i;++j)
            {
                if(i-j<2)
                {
                    dp[j][i]=(s[i]==s[j]);
                }
                else
                {
                    dp[j][i]=(s[i]==s[j]&&dp[j+1][i-1]);
                }
                if((i-j+1)>max_length&&dp[j][i])
                {
                    max_length=i-j+1;
                    start = j;
                }
            }
        }
        string sub = s.substr(start,max_length);
        return sub;
    }
};

int main(int argc, char *argv[])
{
    Solution1 s;
    s.longestPalindrome("a");
    s.longestPalindrome("bb");
    s.longestPalindrome("bbb");
    s.longestPalindrome("bbbb");

    s.longestPalindrome("abcccacc");
    s.longestPalindrome("abccc");
    s.longestPalindrome("abccabxcccexxxxxxec");
    s.longestPalindrome("abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa");

    return 0;
}
