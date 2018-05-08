#include <iostream>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        if(s.size()==0)
            return 0;
        if(s.size()==1)
            return 1;
        bool isP[1000][1000];
        for(int i=0;i<1000;++i)
        {
            for(int j=0;j<1000;++j)
                isP[i][j]=false;
        }
        for(int i=0;i<s.size()-1;++i)
        {
            isP[i][i]=true;
            if(s[i]==s[i+1])
            {
                isP[i+1][i]=true;
//                isP[i][i+1]=true;
            }
        }
        isP[s.size()-1][s.size()-1]=true;
        for(int i=0;i<s.size();++i)
        {
            for(int j=i+2;j<s.size();++j)
            {
                if(s[i]==s[j])
                {
                    isP[i][j]=isP[i+1][j-1];
                }
                else
                {
                    isP[i][j]=false;
                }
            }
        }
        int count=0;
        for(int i=0;i<1000;++i)
            for(int j=0;j<1000;++j)
            {
                if(isP[i][j]==true)
                    count++;
            }
        return count;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    s.countSubstrings("aaa");
    s.countSubstrings("aba");
    return 0;
}

