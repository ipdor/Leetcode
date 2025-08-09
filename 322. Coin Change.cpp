//https://leetcode.com/problems/coin-change/
//2025.8.9创建文件并第一次AC，未看题解
//为了简化代码，可以设置dp默认值为INT_MAX-1,这样每次只要取最小值，最后判断dp[amount]返回-1或正确值即可

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> dp(amount+1, -1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++)
            for (int j = 0; j < coins.size(); j++)
                if(i >= coins[j])
                    //取j-th个物品还是不取？如果两种方式的最小取法都是 -1，结果为 -1；有一个-1则取另一个；都不为-1则取更小值
                    dp[i] = dp[i-coins[j]] == -1 ? dp[i]: (dp[i]==-1?dp[i-coins[j]]+1:min(dp[i], dp[i-coins[j]]+1));

        return dp[amount];
    }
};