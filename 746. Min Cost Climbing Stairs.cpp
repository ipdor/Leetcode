//https://leetcode.com/problems/min-cost-climbing-stairs/description/
//在纸上计算一下，其实不需要回溯法这么麻烦，一次遍历即可计算出dp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        //dp[i]代表到达ith台阶需要的总cost
        vector<int> dp(cost.size()+1, 0);
        for (size_t i = 2; i < cost.size(); i++)
            dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
        return min(dp[cost.size()-1]+cost[cost.size()-1], dp[cost.size()-2]+cost[cost.size()-2]);
    }
};
/*
class Solution {
public:
    void backtrace(vector<int>& cost, vector<int>& dp, int begInd)
    {
        if(begInd== cost.size()-1 || begInd== cost.size()-2)
        {
            dp[cost.size()] = min(dp[begInd] + cost[begInd], dp[cost.size()]);
            return;
        }
        dp[begInd+1] = min(dp[begInd]+ cost[begInd], dp[begInd+1]);
        backtrace(cost, dp, begInd+1);
        dp[begInd+2] = min(dp[begInd]+ cost[begInd], dp[begInd+2]);
        backtrace(cost, dp, begInd+2);
    }
    int minCostClimbingStairs(vector<int>& cost) 
    {
        //dp[i]代表到达ith台阶需要的总cost
        vector<int> dp(cost.size()+1, 9999);
        dp[0] = 0; dp[1] = 0;
        backtrace(cost, dp, 0);
        backtrace(cost, dp, 1);
        return dp[cost.size()];
    }
};
*/