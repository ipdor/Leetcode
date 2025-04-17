//https://leetcode.com/problems/target-sum/description/
//难点1：如何转换为背包问题，2：如何计算组合数量，3：边界情况
//设分成两个组合left和right，所以l+r=sum, l-r=target, 整理可得l = (sum+target)/2, r=(sum-target)/2
//于是转换为容量=l的背包问题，有几种方式填满这个背包
//手画出dp[i][j]的图，可以看出组合数量的计算类似爬楼梯问题，不过是二维的
//2025.04.17创建文件并第一次AC，看了题解
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum< target || (sum+target)%2 || (sum+target)/2<0)
            return 0;

        //nums[i]代表第i个物品的重量
        //从0到nums,共有多少种方式填满
        vector<int> dp((sum+target)/2+1, 0); //left bag size=(sum+target)/2
        for (int i = 0; i < dp.size(); i++)
        {
            if (i==0)
                dp[i]++;
            if(i==nums[0])
                dp[i]++;
        }

        for (int i = 1; i < nums.size(); i++)
        {
            vector<int> now(dp);
            for(int j = 0; j<dp.size(); j++)
            {
                if(nums[i]==0 && j==0)
                    now[j] = dp[j]*2; //子集数量=2^n
                else
                    now[j] = ((j-nums[i])>=0? dp[j-nums[i]]:0) + dp[j];
            }
            dp = now;

            // for(int j = 0; j<dp.size(); j++)
            //     cout<< dp[j] << " ";
            // cout<< endl;
        }

        return dp[dp.size()-1];
    }
};