//https://leetcode.com/problems/word-break/description/
//dp[i]表示从0到i的字符串能被成功分隔
//j<i，如果dp[j]=1&&字符串ji能在wordDict找到，那么dp[i]=1
//对于s = "leetcode", wordDict = ["leet","code"]
//i=1, 1. j=0 字符串ji=l, dp[0]=1, l无法匹配
//i=2, 1. j=0 字符串ji=l, dp[0]=1, l无法匹配 2. j=1, 字符串ji=le, dp[1]=0
//......
//2025.8.10创建文件并第一次AC，是否看题解：true

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size()+1, 0);
        dp[0]=1;

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                string strji = s.substr(j, i-j);
                if(dp[j] && set.find(strji)!= set.end())
                    dp[i] = 1;
            }
        }
        return dp[s.size()];
        
    }
};