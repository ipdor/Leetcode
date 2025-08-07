//https://leetcode.com/problems/combination-sum-iv/description/
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0377.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8C%E2%85%A3.md
//2025.8.7创建文件并第一次AC，看题解
//注意背包/物品遍历顺序的影响，和518题的区别。

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        //dp[i]代表装满容量为i的背包有几种方式
        vector<unsigned int>  dp(target+1, 0);
        dp[0] = 1;
        for (int i = 1; i < dp.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (i >= nums[j])
                {
                    //当前背包容量为i。为了使用前0-j个物品装满背包，根据装不装物品j分为两种不同方式。dp[i]等于两种方式之和
                    //1. 不装物品j，共dp[i]种方式
                    //2. 装物品j。最后一个物品留给j，占用nums[j]，剩余x=i-nums[j]空间自由排列。这种方式总数=使用前0-j个物品装满大小为x的背包方式总数=dp[i-nums[j]]
                    dp[i] += dp[i- nums[j]];
                }
            }
        }
        return dp[target];
    }
};
