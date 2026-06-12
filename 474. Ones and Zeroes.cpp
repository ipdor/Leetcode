// https://leetcode.com/problems/ones-and-zeroes/
// 这道题的特点是求有多少种装满背包的方法，解法依然是01背包，但是是二维
// dp[i][j]定义为不超过i个0，j个1的strs的最大子集数量。
// 求解法是遍历每个字符串，更新可以容下它的所有dp[i][j]
// 2025.04.30 第一次AC，看了题解
// 2026.06.12 第二次AC，看了题解

// 第二次AC
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (string  str: strs)
        {
            int n0 = 0, n1 = 0;
            for(char c:str)
                (c=='0')? (n0++) : n1++;
            
            //cout << n0 << " " << n1 << endl;

            for(int i=m; i>=n0; i--)
                for (int j=n; j>=n1; j--)
                    dp[i][j] = max(dp[i][j], dp[i-n0][j-n1]+1); //别忘了需要比较加入当前物品能否获得更大子集
        }
        return dp[m][n];
    }
};

// 第一次AC
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        vector<vector<int>> dp(m+1, vector(n+1,0));
        for(string s: strs)
        {
            int zeros = 0, ones = 0;
            for(auto ch:s)
            {
                if(ch=='0') zeros++;
                else ones++;
            }
            //必须倒序遍历，否则后面的dp[i][j]会根据前面更新过的dp[i][j]再次更新，导致多次相加出错
            for(int i = m; i>=zeros; i--)
                for(int j = n; j>=ones; j--)
                    dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones]+1);
        }
        return dp[m][n];
    }
};

/*

    纯 0 - 1 背包 是求 给定背包容量 装满背包 的最大价值是多少。
    416. 分割等和子集 是求 给定背包容量，能不能装满这个背包。
    1049. 最后一块石头的重量 II 是求 给定背包容量，尽可能装，最多能装多少
    494. 目标和 是求 给定背包容量，装满背包有多少种方法。
    本题474. 是求 给定背包容量，装满背包最多有多少个物品。

*/