//https://leetcode.com/problems/unique-binary-search-trees/
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0096.%E4%B8%8D%E5%90%8C%E7%9A%84%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91.md
//自己没想出来
//n=3时，1为根节点，右边有2个节点，左边有0个节点，所以是dp[2]*dp[0];
//n=3时，2为根节点，右边有1个节点，左边有1个节点，所以是dp[1]*dp[1];
//n=3时，3为根节点，右边有0个节点，左边有2个节点，所以是dp[0]*dp[2];
//以此类推，dp[i] = dp[i-j]*dp[j-1];
class Solution {
public:
    int numTrees(int n) 
    {
        vector<int> dp(max(3,n+1), 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (size_t i = 3; i <=n; i++)
        {
            //共i个节点，根节点为j, 右边有i-j个节点, 左边有i-1-(i-j)=j-1个节点
            int rightnum = i-1;
            for (size_t j = 1; j <= i; j++)
                dp[i] += dp[i-j] * dp[j-1];
        }
        
        return dp[n];
    }
};