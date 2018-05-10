#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countSubstrings(string s)
    {
        if(s.size()==0)
            return 0;
        vector<vector<bool>> array(s.size(),vector<bool>(s.size(),false));
        for(int i=0;i<array.size();++i)
        {
            array[i][i]=true;
            if((i+1)==array.size())
                break;
            if(s[i]==s[i+1])
            {
                array[i][i+1]=true;
            }
        }
        for(int len=3;len<=s.size();++len)
        {
            for(int i=0;i<s.size();++i)
            {
                int j=i+len-1;
                if(j>s.size()-1)
                    continue;
                if(s[i]==s[j])
                {
                    array[i][j]=array[i+1][j-1];
                }
                else
                {
                    array[i][j]=false;
                }
            }
        }
        int count=0;
        for(int i=0;i<array.size();++i)
        {
            for(int j=0;j<array[i].size();++j)
            {
                if(array[i][j])
                    count++;
            }
        }
        return count;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    s.countSubstrings("aaaaa");
    s.countSubstrings("aba");
    return 0;
}

