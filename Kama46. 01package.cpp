//https://kamacoder.com/problempage.php?pid=1046
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E8%83%8C%E5%8C%85%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%8001%E8%83%8C%E5%8C%85-1.md
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E8%83%8C%E5%8C%85%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%8001%E8%83%8C%E5%8C%85-2.md
#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int m, n;
    cin >> m >> n;

    vector<int> space(m);
    vector<int> value(m);
    for (int i = 0; i < m; ++i)
    cin >> space[i];
    for (int i = 0; i < m; ++i)
    cin >> value[i];

    // dp[i][j]表示前i个物品，背包容量为j时的最大价值
    vector<vector<int>> dp(m, vector<int>(n + 1, 0));
    for (size_t j = 0; j < dp[0].size(); j++) 
        dp[0][j] = j>=space[0]? value[0]: 0;
    
    for (size_t i = 1; i < dp.size(); i++) 
    {
        if(i==0)
            dp[0][j] = j>=space[0]? value[0]: 0;
        for (size_t j = 0; j < dp[0].size(); j++) 
        {
            if (j == 0)
                dp[i][j] = 0;
            else
                dp[i][j] = (j < space[i])? dp[i - 1][j] : max(dp[i - 1][j], dp[i - 1][j - space[i]] + value[i]);
        }
    }
    cout << dp[m - 1][n] << endl;

    return 0;
}