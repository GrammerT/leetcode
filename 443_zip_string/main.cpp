#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size()<=0)
            return 0;
        if(chars.size()==1)
            return 1;
        vector<char> tmp_chars;
        char tmp = chars[0];
        int tmp_size = 1;
        for(int i=1;i<chars.size();++i)
        {
            if(tmp==chars[i])
            {
                tmp_size++;
            }
            else
            {
                if(1==tmp_size)
                {
                    tmp_chars.push_back(chars[i-1]);
                    tmp=chars[i];
                    tmp_size = 1;
                }
                else
                {
                    vector<char> nums;
                    while(tmp_size)
                    {
                        char value = tmp_size%10+'0';
                        nums.insert(nums.begin(),value);
                        tmp_size/=10;
                    }
                    tmp_chars.push_back(chars[i-1]);
                    tmp_chars.insert(tmp_chars.end(),nums.begin(),nums.end());
                    tmp=chars[i];
                    tmp_size = 1;
                }
            }
        }
        vector<char> nums;
        while(tmp_size)
        {
            char value = tmp_size%10+'0';
            nums.insert(nums.begin(),value);
            tmp_size/=10;
        }
        tmp_chars.push_back(tmp);
        tmp_chars.insert(tmp_chars.end(),nums.begin(),nums.end());
        chars.insert(chars.begin(),tmp_chars.begin(),tmp_chars.end());
        return tmp_chars.size();
    }
};

int main(int argc, char *argv[])
{
    vector<char> v;
    v.push_back('a');
    v.push_back('a');
    v.push_back('b');
    v.push_back('b');
    v.push_back('c');
    v.push_back('c');
    v.push_back('c');
    Solution s;
    int b = s.compress(v);
    v.clear();
    v.push_back('a');
    v.push_back('a');
    v.push_back('b');
    v.push_back('b');
    v.push_back('c');
    v.push_back('c');
    v.push_back('c');
    v.push_back('c');
    v.push_back('c');
    v.push_back('c');
    v.push_back('c');
    v.push_back('c');
    v.push_back('c');
    v.push_back('c');
    v.push_back('c');
    v.push_back('c');
    v.push_back('c');
    b = s.compress(v);
    return 0;
}
