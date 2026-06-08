// https://kamacoder.com/problempage.php?pid=1066
// 把n个物品j当成 n个物品i,i+1,i+2...i+n, 然后当成01背包解决
// 2026.06.08 第一次AC

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int c, n;
    cin >> c >> n;
    vector<int> weight(n, 0), value(n,0), maxcnt(n, 0);

    for (size_t i = 0; i < n; i++)
        cin >> weight[i];
    
    for (size_t i = 0; i < n; i++)
        cin >> value[i];
    
    for (size_t i = 0; i < n; i++)
        cin >> maxcnt[i];
    
    vector<int> dp(c+1, 0);
    dp[0] = 0;
    for (size_t i = 0; i < n;)
    {
        maxcnt[i]--;
        for (size_t j = 1; j <= c; j++)
        {
            if (j-weight[i]>=0)
            {
                dp[j] = max(dp[j], dp[j-weight[i]]+ value[i]);
            }
            for (size_t k = 0; k <= c; k++) cout<< dp[k] << " ";
            cout <<endl;

        }
        if (!maxcnt[i])
            i++;
    }
    cout<< dp[c];
    return 0;
    
}