//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
//本题把极值-fee，然后用122题的贪心法并不好做，需要考虑很多情况。应该用动态规划。
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
    }
};
/*错误代码。
//用例[4,5,5,2,4,3,5,5,2,3],fee=3; [4,5,2,4,3,3,1,2,5,4],fee =1
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        vector<int> deductedPrice(prices);
        int indBuy = -1;
        for (size_t i = 0; i < prices.size(); i++)
        {
            if(indBuy==-1 || prices[i] < prices[indBuy])
            {
                indBuy = i;
                continue;
            }
            if(indBuy>=0 && prices[i] > prices[indBuy])
                deductedPrice[i] = max(prices[indBuy], prices[i]-fee);
            if (prices[i] > prices[i+1])
                indBuy = -1;
        }
        
        for (size_t i = 0; i < prices.size(); i++)
        {
            cout << deductedPrice[i]<< " ";
        }
        cout<<endl;
        indBuy = -1;
        int maxProfit = 0;
        for (size_t i = 0; i < deductedPrice.size(); i++)
        {
            cout << "i="<< i<< " "<< deductedPrice[i]<< " "<< indBuy << " ";
            if(indBuy==-1 || deductedPrice[i] < deductedPrice[indBuy])
            {
                indBuy = i;
                continue;
            }
            if (i==deductedPrice.size()-1 || deductedPrice[i]> deductedPrice[i+1])
            {
                cout<< " profit+=" deductedPrice[i] <<"-" << deductedPrice[indBuy] <<endl;
                indBuy = -1;
                maxProfit+= deductedPrice[i] - deductedPrice[indBuy];
            }
            cout << "end"<<endl;
        }
        return maxProfit;
    }
};
*/