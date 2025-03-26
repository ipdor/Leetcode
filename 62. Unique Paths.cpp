//https://leetcode.com/problems/unique-paths/
//可以简化成一维数组，因为每次只需要上一行的数据
class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        vector<int> lastrow(n,1);
        for(int i = 1; i < m; ++i)
        {
            vector<int> row(n,1);
            for(int j = 1; j < n; ++j)
                row[j] = lastrow[j] + row[j-1];
            lastrow = row;
        }
        return lastrow[n-1];
    }
};
/*
class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> board(m, vector<int>(n,1));
        for(int i = 0; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                if (i==0)
                {
                    board[i][j] = board[i][j-1];
                }
                else if (j==0)
                {
                    board[i][j] = board[i-1][j];
                }
                else
                {
                    board[i][j] = board[i-1][j] + board[i][j-1];
                }   
            }
        }
        return board[m-1][n-1];
    }
};
*/