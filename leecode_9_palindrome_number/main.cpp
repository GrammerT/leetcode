#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        if(x<10)
            return true;
        char *dst=(char*)malloc(1024);
        sprintf(dst,"%d",x);
        string str(dst);
        for(int i=0;i<str.size()/2;++i)
        {
            if(str[i]==str[str.size()-i-1])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

//! optimization
class Solution1 {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        if(x<10)
            return true;
        int result = 0;
        int tmp=0;
        int tmpx=x;
        while(x!=0)
        {
            tmp=x%10;
            result=10*result+tmp;
            x/=10;
        }
        if(result==tmpx)
            return true;
        else
            return false;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    int n;
    while(cin>>n)
    {
        if(n==0)
            return 0;
        cout<<s.isPalindrome(n)<<endl;
    }
    return 0;
}
