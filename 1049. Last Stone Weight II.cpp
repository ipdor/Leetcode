//https://leetcode.com/problems/last-stone-weight-ii/description/
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/1049.%E6%9C%80%E5%90%8E%E4%B8%80%E5%9D%97%E7%9F%B3%E5%A4%B4%E7%9A%84%E9%87%8D%E9%87%8FII.md
//把石头分成两堆，他们的重量差就是最后的重量，所以转换成求两堆石头重量差最小是多少。
//类似416题，可以再转换成01背包问题: 一堆石头的重量和价值是stones[i],求接近一半重量/价值的最大重量/价值。ans=两堆石头重量差绝对值=abs(maxhalf - (sum-maxhalf))
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) 
    {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        vector<int> dp(sum+1, 0);
        int maxhalf = 0; //不超过一半的一堆石头，重量最大是多少。越接近一半那么差越小
        for (size_t i = 0; i < stones.size(); i++)
        {
            for (int j = dp.size()-1; j >= stones[i]; j--)
            {
                dp[j] = max(dp[j], dp[j-stones[i]]+stones[i]);
                if (dp[j]<= sum/2 && dp[j]> maxhalf)
                    maxhalf = dp[j];
            }
        }
        return abs(maxhalf - sum+ maxhalf);
    }
};