//https://kamacoder.com/problempage.php?pid=1046
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E8%83%8C%E5%8C%85%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%8001%E8%83%8C%E5%8C%85-1.md
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E8%83%8C%E5%8C%85%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%8001%E8%83%8C%E5%8C%85-2.md
#include <iostream>
#include <vector>
using namespace std;
//因为计算第i行数据只需要用到第i-1行数据，所以可以只用一个一维数组来存储数据
//此时必须倒序遍历背包空间，否则可能会把物品多次放入
void collect(int n, int m, vector<int>& space, vector<int>& value)
{
    vector<int> dp(n + 1, 0);
    for (size_t i = 0; i < m; i++)
    {
        //注意循环变量如果减一定要用int而不是size_t，否则死循环
        for (int j = n; j >=space[i]; j--)
        {
            dp[j] = max(dp[j- space[i]]+ value[i], dp[j]);
        }
    }
    cout<< dp.back()<< endl;
}

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
    collect(n, m, space, value);
    return 0;
}

/*
//完整版
void collect(int n, int m, vector<int>& space, vector<int>& value)
{
    // dp[i][j]表示前i个物品，背包容量为j时的最大价值
    vector<vector<int>> dp(m, vector<int>(n + 1, 0));
    for (size_t j = 0; j < dp[0].size(); j++) 
        dp[0][j] = j>=space[0]? value[0]: 0;
    
    for (size_t i = 1; i < dp.size(); i++) 
    {
        for (size_t j = 0; j < dp[0].size(); j++) 
        {
            if (j == 0)
                dp[i][j] = 0;
            else
                dp[i][j] = (j < space[i])? dp[i - 1][j] : max(dp[i - 1][j], dp[i - 1][j - space[i]] + value[i]);
        }
    }
    cout << dp[m - 1][n] << endl;
}
*/