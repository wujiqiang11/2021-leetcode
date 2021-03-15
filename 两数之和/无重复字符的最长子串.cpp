#include<map>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int maxLen = 0;
        if (len == 0)
            return maxLen;
        map<char, int> hashMap;
        char temp;
        int j = 0;
        int lenTemp = 0;
        for (int i = 0; i < len; i++)
        {
            temp = s[i];
            if (hashMap.find(temp) == hashMap.end())
            {
                hashMap.insert(pair<char, int>(temp, 1));
                lenTemp++;
                if (lenTemp > maxLen)
                {
                    maxLen = lenTemp;
                }
            }
            else
            {
                if (hashMap[temp] == 0)
                {
                    hashMap[temp]++;
                    lenTemp++;
                    if (lenTemp > maxLen)
                    {
                        maxLen = lenTemp;
                    }
                }
                else
                {
                    while (s[j] != temp)
                    {
                        hashMap[s[j]]--;
                        j++;
                        lenTemp--;
                    }
                    j++;
                    
                }
            }
        }
        return maxLen;
    }
};