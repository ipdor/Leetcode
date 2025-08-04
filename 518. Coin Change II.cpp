//https://leetcode.com/problems/coin-change-ii/description/
//参考01背包组合问题lc.494
//2025.8.4创建文件并第一次AC，未看题解

class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        vector<unsigned int> dp(amount+1, 0);  //类型必须unsigned
        dp[0] = 1;

        for (int i = 0; i < coins.size(); i++)
            for (int j = coins[i]; j < dp.size(); j++)
                dp[j] = dp[j] + dp[j-coins[i]]; //题目保证答案在32-bit integer范围，但是中间结果不保证
            
        return dp[amount];
    }
};