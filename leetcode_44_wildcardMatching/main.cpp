#include <iostream>
#include <vector>

using namespace std;

//! error.
class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.size()==0&&p.size()==0)
            return true;
        if(s.size()==0)
        {
            if(p[0]=='?'&&p.size()==1)
                return true;
            for(int i=0;i<p.size();++i)
            {
                if(p[i]!='*')
                {
                    return false;
                }
            }
            return true;
        }
        if(p.size()==0)
        {
            if(s.size()>0)
                return false;
            return true;
        }
        //! p.size()>0 and s.size()>0
        bool matchArray[1000][1000];

        if(p[0]=='*')
        {
            for(int i=0;i<s.size();++i)
            {
                matchArray[0][i]=true;
            }
        }
        for(int j=1;j<p.size();++j)
        {
            for(int i=1;i<s.size();++i)
            {
                if(p[j]=='?')
                {
                    matchArray[j][i]=matchArray[j-1][i-1];
                    continue;
                }
                if(p[j]=='*')
                {
                    for(int k=i;i<s.size();++i)
                    {
                        matchArray[j][k]=true;
                    }
                    continue;
                }
                if(p[j]==s[i])
                {
                    matchArray[j][i]=matchArray[j-1][i-1];
                    continue;
                }
                else
                {
                    matchArray[j][i]=false;
                }
            }
        }
        bool b = matchArray[p.size()-1][s.size()-1];
        return b;
    }
};

int main(int argc, char *argv[])
{
    Solution  s;
    s.isMatch("adceb","*a*b");
    s.isMatch("acdcb","a*c?b");
    return 0;
}
