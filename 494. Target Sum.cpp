//https://leetcode.com/problems/target-sum/description/
// 难点1：如何转换为背包问题，2：如何计算组合数量，3：边界情况
// 设分成两个组合left和right，所以l+r=sum, l-r=target, 整理可得l = (sum+target)/2, r=(sum-target)/2
// 于是转换为容量=l的背包问题，有几种方式填满这个背包
// 手画出dp[i][j]的图，可以看出组合数量的计算类似爬楼梯问题，不过是二维的
// 2025.04.17 创建文件并第一次AC，看了题解
// 2026.06.11 第二次AC，看了题解

//第二次AC 
/*
难点在于边界条件：
1. target可以为负数
    负数且小于-sum (sum+target<0): 和 target>sum一样无解，对应绝对值大于sum的情况
    -sum<=target<=sum：正常求解
2. 0元素的dp值
    第一个元素为0：第一行dp[0][nums[0]] += 1 而不是设为1
    第 i >1 个元素为0：每行从第0列开始遍历
3. nums[0] > space
    如果 nums[0]<= space 才设dp[i][j]值
*/

// 一维解法
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(abs(target) > sum)   return 0;
        if((sum+target) % 2)    return 0;

        int space = (sum+target)/2;
        vector<int> dp(space+1, 0);
        dp[0] = 1;
        if(nums[0] <= space)
            dp[nums[0]] += 1;
        
        // for(int j=0; j<= space; j++)
        //         cout << dp[j] << " ";
        // cout << endl;
        for(int i=1; i<nums.size(); i++)
        {
            for (int j = space; j>=0; j--)
            {
                if(j >= nums[i])
                    dp[j] += dp[j - nums[i]];
            }
            // for(int j=0; j<= space; j++)
            //     cout << dp[j] << " ";
            // cout << endl;
        }
        return dp[space];
    }
};


// 第二次AC，二维dp解法
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(abs(target)>sum) return 0;
        if((target+sum)%2) return 0;

        int space = (target+sum)/2;
        vector<vector<int>> dp(nums.size(), vector<int>(space+1, 0));
        for(int i=0; i<nums.size(); i++)
            dp[i][0] = 1;
        if(nums[0] <= space)
            dp[0][nums[0]] += 1;

        // for(int j=0; j<=space; j++)
        //         cout << dp[0][j] << " ";
        // cout << endl;

        for(int i=1; i<nums.size(); i++)
        {
            // 元素可能是0，从0开始
            for(int j=0; j<=space; j++)
            {
                dp[i][j] = dp[i-1][j];
                if(j>=nums[i]) 
                    dp[i][j] += dp[i-1][j-nums[i]];
            }
            // for(int j=0; j<=space; j++)
            //     cout << dp[i][j] << " ";
            // cout << endl;
        }
        return dp[nums.size()-1][space];
    }
};




// 第一次
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