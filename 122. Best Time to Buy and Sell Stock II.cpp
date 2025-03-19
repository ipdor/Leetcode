//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
//画出折线图后很明显可以看出，每次取单调递增的上下限即可获得全局最大值
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int indbuy = -1, maxProfit=0;
        for (size_t i = 0; i < prices.size(); i++)
        {
            if (indbuy == -1 || prices[indbuy] > prices[i])
            {
                indbuy = i;
                continue;
            }
            if (i==prices.size()-1 || prices[i] > prices[i+1])
            {
                maxProfit += prices[i] - prices[indbuy];
                indbuy = -1;
            }
        }
        return maxProfit;
    }
};