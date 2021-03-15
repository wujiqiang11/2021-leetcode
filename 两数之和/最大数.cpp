#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    /**
     * 最大数
     * @param nums int整型vector
     * @return string字符串
     */
    string solve(vector<int>& nums) {
        // write code here
        vector<string> lists;
        for (int i = 0; i < nums.size(); i++)
        {
            lists.push_back(to_string(nums[i]));

        }
        sort(lists.begin(), lists.end(), cmp);
        string s = "";
        for (int i = 0; i < lists.size(); i++)
        {
            s = s + lists[i];
        }
        if (s[0] == '0')
        {
            return "0";
        }
        else
        {
            return s;
        }
    }
    static bool cmp(string s1, string s2)
    {
        return s1 + s2 > s2 + s1;
    }
};

