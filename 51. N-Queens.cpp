//https://leetcode.com/problems/n-queens/
//每步对下一个坐标进行验证，可行再继续找解，如果一次验证一个棋盘很麻烦。
//直接传入vector<string>作为棋盘应该会更快
class Solution {
public:
    bool IsValid(int x, int y, vector<vector<int>> &board)
    {
        int n = board.size();
        //不用验证行，本来就是按行探索；不用验证下面，因为下面还没棋子
        //列
        for(int i=0;i<n;i++)
            if (board[i][y])
                return false;
        
        //左上
        for(int i=x-1, j=y-1; i>=0 && j>=0; i--, j--)
            if (board[i][j])
                return false;
        
        //右上
        for(int i=x-1, j=y+1; i>=0 && j<n; i--, j++)
            if (board[i][j])
                    return false;

        return true;
    }
    void backtrace(vector<vector<int>> &board, int row, int n, vector<vector<string>>& ans)
    {
        if (row ==n)
        {
            vector<string> scheme;
            //board转换为ans格式
            for(int i=0;i<n;i++)
            {
                string row;
                for(int j=0;j<n;j++)
                    row += board[i][j]?'Q':'.';
                scheme.push_back(row);
            }
            ans.push_back(scheme);
            return;
        }
        for (size_t j = 0; j < n; j++)
        {
            if (board[row][j]==0 && IsValid(row, j, board))
            {
                board[row][j] = 1;
                backtrace(board, row+1, n, ans);
                board[row][j] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<int>> board;
        vector<vector<string>> ans;
        for(int i=0;i<n;i++)
        {
            vector<int> row;
            for(int j=0;j<n;j++)
                row.push_back(0);
            board.push_back(row);
        }
        backtrace(board, 0, n, ans);
        return ans;
    }
};