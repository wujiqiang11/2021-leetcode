#include<vector>
using namespace std;

class Solution {
public:
    /**
     *
     * @param prices int整型vector
     * @return int整型
     */
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
        int i = 0;
        int max_bonus = 0;
        for (int j = 1; j < prices.size(); j++)
        {
            if (prices[j] >= prices[i])
            {
                if (prices[j] - prices[i] > max_bonus)
                {
                    max_bonus = prices[j] - prices[i];
                }
            }
            else
            {
                i = j;
            }
        }
        return max_bonus;
        // write code here
    }
};