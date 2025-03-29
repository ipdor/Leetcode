//https://leetcode.com/problems/partition-equal-subset-sum/
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0416.%E5%88%86%E5%89%B2%E7%AD%89%E5%92%8C%E5%AD%90%E9%9B%86.md
//回溯法可以做但是提交会超时
//转换为背包问题，nums视为重量和价值，把容量=sum/2的背包填满；而不是把nums视为价值，重量视为1，找总value能否等于sum/2
class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        //当nums每个数字视为重量和价值均为nums[i]的物品，那么dp[i]代表背包容量为i时，此时能携带的最大价值，这里也是其重量。
        //如果dp[i]==i那么说明最大重量（最大价值）=背包重量，装满了
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total%2)
            return false;
        vector<int> dp(total/2+1, 0);
        for (size_t i = 0; i < nums.size(); i++)
        {
            for (int j = dp.size()-1; j >=nums[i]; j--) //注意下限是闭区间
            {
                dp[j] = max(dp[j], dp[j-nums[i]]+ nums[i]);
                if(dp[j] == total/2)
                    return true;
            }
            // for (int j = 0; j < dp.size(); j++)
            //     cout<< dp[j] << " ";
            // cout<< endl;
        }
        return false;
    }
};