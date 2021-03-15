#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hash;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            if (hash.find(target - nums[i])!=hash.end())
            {
                result.push_back(i);
                result.push_back(hash[target - nums[i]]);
            }
            hash.insert(pair<int, int>(nums[i], i));
        }
        return result;
    }
};