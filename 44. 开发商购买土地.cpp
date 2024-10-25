//https://kamacoder.com/problempage.php?pid=1044
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    int m,n, rows, cols;
    cin>> n>>m;
    
    rows=n;
    cols=m;
    if (rows==1 && cols==1)
    {
        int a;
        cin>> a;
        cout<< a<< endl;
        return 0;
    }

    vector<vector<int>> lands;
    vector<int>cumLands;   //各行/列土地总和，前n个行，后m个是列
    /*
    3 3
    1 2 3
    2 1 3
    1 2 3
    各行土地数6 6 6，各列4 5 9。分别按行/列计算前缀和得到6 12 18，4 9 18
    组合成一个m+n的数组[6,12, 18, 4, 9, 18]，下标[0,n-1]属于行的前缀和[n,n+m-1]属于列的前缀和
     */
    
    while (n--)
    {
        vector<int> row;
        int cumRow=0;
        int num = m;
        while (num--)
        {
            int land;
            cin >> land;
            row.push_back(land);
            cumRow+=land;
        }
        lands.push_back(row);
        cumLands.push_back(cumRow);
    }

    for (int j = 0; j < cols; j++)
    {
        int cumCol=0;
        for (int i = 0; i < rows; i++)
        {
            cumCol += lands[i][j];  
        }
        cumLands.push_back(cumCol);
    }


    // for (int i = 0; i < cumLands.size(); i++)
    // {
    //     cout<< cumLands[i]<< " ";     
    // }
    // cout<< endl;

    for (int i = 0; i < cumLands.size(); i++)
    {
        if (i>0 && i!= rows)
        {
            cumLands[i]+=cumLands[i-1];
        }
    }

    int minGap=1e7;
    for (int i = 0; i < cumLands.size(); i++)
    {
        int gap;
        //gap=abs([i] - ([m-1] - [i])) = abs(2[i] - [m-1])
        if (i<rows-1)
        {
            gap = abs(2*cumLands[i] - cumLands[rows-1]);
            //cout<< i<<" "<< cumLands[i] <<" " <<cumLands[rows-1]<<" "<< gap<< endl;
        }
        else if (i>rows-1 && i< rows+cols-1)
        {
            gap = abs(2*cumLands[i] - cumLands[rows+cols-1]);
            //cout<< i<<" "<< cumLands[i] <<" " <<cumLands[rows+cols-1]<<" "<< gap<< endl;
        }
        if (gap<minGap)
            minGap = gap;
    }
    
    cout<< minGap<< endl;
}

/*下面代码思路更清晰,更简单
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0044.%E5%BC%80%E5%8F%91%E5%95%86%E8%B4%AD%E4%B9%B0%E5%9C%9F%E5%9C%B0.md
#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int main () {
    int n, m;
    cin >> n >> m;
    int sum = 0;
    vector<vector<int>> vec(n, vector<int>(m, 0)) ;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> vec[i][j];
            sum += vec[i][j];
        }
    }

    int result = INT_MAX;
    int count = 0; // 统计遍历过的行
    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < m; j++) {
            count += vec[i][j];
            // 遍历到行末尾时候开始统计
            if (j == m - 1) result = min (result, abs(sum - count - count));

        }
    }

    count = 0; // 统计遍历过的列
    for (int j = 0; j < m; j++) {
        for (int i = 0 ; i < n; i++) {
            count += vec[i][j];
            // 遍历到列末尾的时候开始统计
            if (i == n - 1) result = min (result, abs(sum - count - count));
        }
    }
    cout << result << endl;
}
 */