//https://leetcode.com/problems/sudoku-solver/
//注意：1.验证函数，2.找到一个解就立即返回，此时棋盘就是正确结果
class Solution {
public:
    bool valid(vector<vector<char>>& board, int row, int col, int val)
    {
        for (size_t j = 0; j < 9; j++)
            if(board[row][j]==val || board[j][col]==val)
                return false;
        
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++)
            for (int j = startCol; j < startCol + 3; j++) 
                if (board[i][j] == val ) 
                    return false;
                
        return true;
    }
    //不用传坐标，因为每次要从头遍历整个棋盘
    bool solve(vector<vector<char>>& board)
    {
        for (size_t i = 0; i < 9; i++)
        {
            for (size_t j = 0; j < 9; j++)
            {
                if(board[i][j]=='.')
                {
                    for (size_t val = '1'; val <='9'; val++)
                    {
                        if (valid(board, i, j, val))
                        {
                            board[i][j] = val;
                            if (solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) 
    {
        solve(board);
    }
};