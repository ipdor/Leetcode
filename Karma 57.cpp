//https://kamacoder.com/problempage.php?pid=1067
//2025.8.8创建文件并第一次AC，未看题解
#include<iostream>
#include<vector>

using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(int i =1; i<=n; i++)
    {
        for(int j = 1; j<=m; j++)
            if(i >= j)
                dp[i] += dp[i-j];
    }
    cout << dp[n] ;
    return 0;
}