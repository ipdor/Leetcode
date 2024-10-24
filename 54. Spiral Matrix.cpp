//https://leetcode.com/problems/spiral-matrix/description/
//参考 https://blog.csdn.net/qq_17550379/article/details/83148050
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int size= m*n;
        int x1=0, y1=0, x2=m-1, y2=n-1;
        vector<int> res;
        while (x2>=x1 && y2>=y1)
        {
            //最上面一行 (x1, [y1,y2])
            for (size_t j = y1; j <= y2; j++)
            {
                res.push_back(matrix[x1][j]);
            }
            //最右边一列 ((x1,x2], y2)
            for (size_t i = x1+1; i <= x2; i++)
            {
                res.push_back(matrix[i][y2]);
            }
            //中间可能只有一列或一行
            if (x2>x1 && y2>y1)
            {
                //最下面一行 (x2, (y2,y1))
                for (size_t j = y2-1; j > y1; j--)
                {
                    res.push_back(matrix[x2][j]);
                }
                //最左边一列 ([x2,x1）, y1)
                for (size_t i = x2; i > x1; i--)
                {
                    res.push_back(matrix[i][y1]);
                }
            }
            x1++;
            y1++;
            x2--;
            y2--;
            
        }
        return res;

    }
};