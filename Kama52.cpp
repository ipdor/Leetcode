//https://kamacoder.com/problempage.php?pid=1052
//[背包问题分类,01完全多重分组](https://camo.githubusercontent.com/0f6365953e879c2bdc077b00aa6b7f0278a9d0cee9a9553d441857c1da03e186/68747470733a2f2f66696c65312e6b616d61636f6465722e636f6d2f692f616c676f2f32303231303131373137313330373430372e706e67)
//2025.8.4创建，看了题解
#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &dp)
{
    for (int j =0; j< dp.size(); j++)
        cout<< dp[j]<< " ";
    cout << endl;
}

void collect(int totalV, int cnt, vector<int> &space, vector<int> &value, vector<int> &dp)
{
    //初始化第0行
    for(int j = space[0]; j<dp.size(); j++)
        dp[j] = dp[j - space[0]] + value[0];

    //遍历计算
    for(int i = 1;i<space.size(); i++)
    {
        for (int j =1; j< dp.size(); j++)
        {
            //完全背包和01背包的主要区别在这里
            //如果取物品i，那么扣除space[i]后，应该计算可以取物品i的最大价值dp[i][j-space[i]]，和i的价值value[i]相加
            //可以简化为一维，不取物品i则直接使用当前dp[j]，否则计算dp[j-space[i]]+value[i]
            if (j>=space[i])
                dp[j] = max(dp[j],  dp[j-space[i]]+ value[i]);    
        }
    }
}

int main() 
{
    int n, totalV, weight, value;
    cin >> n >> totalV;

    vector<int> vecspace(n);
    vector<int> vecval(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> weight >> value;
        vecspace[i] = weight;
        vecval[i] = value;
    }

    vector<int> dp(totalV+1, 0);
    collect(totalV, n, vecspace, vecval, dp);
    // print(dp);
    cout<< dp[dp.size()-1];
    return 0;
}


//二维dp
/*
#include <iostream>
#include <vector>
using namespace std;

void collect(int totalV, int cnt, vector<int> &space, vector<int> &value, vector<vector<int>> &dp)
{
    //初始化第0行
    for(int j = space[0]; j<dp[0].size(); j++)
        dp[0][j] = dp[0][j - space[0]] + value[0];
    
    //遍历计算
    for(int i = 1;i<dp.size(); i++)
    {
        for (int j =1; j< dp[0].size(); j++)
        {
            //完全背包和01背包的主要区别在这里
            //如果取物品i，那么扣除space[i]后，应该计算可以取物品i的最大价值dp[i][j-space[i]]，和i的价值相加
            dp[i][j] =  (j<space[i])?dp[i-1][j] :max(dp[i-1][j],  dp[i][j-space[i]]+ value[i]);    
        }
    }
}

void print(vector<vector<int>> &dp)
{
    for(int i = 0;i<dp.size(); i++)
    {
        for (int j =0; j< dp[0].size(); j++)
            cout<< dp[i][j]<< " ";
        cout << endl;
    }
}

int main() 
{
    int n, totalV, weight, value;
    cin >> n >> totalV;

    vector<int> vecspace(n);
    vector<int> vecval(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> weight >> value;
        vecspace[i] = weight;
        vecval[i] = value;
    }

    vector<vector<int>> dp(n, vector<int>(totalV+1, 0));
    collect(totalV, n, vecspace, vecval, dp);
    //print(dp);
    cout<< dp[dp.size()-1][dp[0].size()-1];
    return 0;
}
*/