#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = -1;
        map<char,int> chartolength;
        int listLength=1;
        chartolength[s.at(0)]=1;
        for(int i=1;i<s.size();++i)
        {
            if(chartolength.count(s.at(i))>0)
            {
                 for (map<char,int>::iterator it=chartolength.begin();
                      it!=chartolength.end(); ++it)
                 {
                    it->second -= (chartolength[s.at(i)]-1);
                 }
            }
            else
            {
                chartolength[s.at(i)]=chartolength[s.at(i-1)]+1;
                if(listLength<chartolength[s.at(i)])
                {
                    listLength=chartolength[s.at(i)];
                }
            }
        }
        return listLength;
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    cout<<s.lengthOfLongestSubstring("bbbbbbb");
    return 0;
}
