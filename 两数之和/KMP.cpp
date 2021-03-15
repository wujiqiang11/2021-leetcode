#include<string>
#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0)
            return 0;
        if (haystack.length() == 0)
            return -1;
        int i = 0;
        int j = 0;
        int loc = -1;
        int hLen = haystack.length();
        int nLen = needle.length();
        vector<int> next = getNext(needle);
        for (int p = 0; p < next.size(); p++)
        {
            cout << next[p] << " ";
        }

        while (i < hLen)
        {
            if (haystack[i] == needle[j])
            {
                i++;
                j++;
                if (j>= nLen)
                {
                    loc = i-nLen;
                    break;
                }
            }
            else
            {
                if (next[j] >= 0)
                {
                    j = next[j];
                }
                else
                {   
                    i++;
                    j = 0;
                }
            }
        }
        return loc;

    }
private:
    vector<int> getNext(string needle)
    {
        int sLen = needle.length();
        vector<int> next(sLen, 0);
        if (sLen >= 2)
        {
            next[0] = -1;
            next[1] = 0;
        }
        else
        {
            next[0] = -1;
        }
        int k;
        for (int i = 1; i < sLen-1; i++)
        {
            k = next[i];
            if (k==-1 || needle[i] == needle[k])
            {
                next[i+1]=k+1;
            }
            else
            {
                while (1)
                {
                    k = next[k];
                    if (k == -1 || needle[i] == needle[k])
                    {
                        next[i + 1] = k + 1;
                        break;
                    }
                }
            }
        }
        return next;
    }
};


