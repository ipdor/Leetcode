//https://leetcode.com/problems/spiral-matrix-ii/description/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> res(n, vector<int>(n));
        int x1=0, y1=0, x2=n-1, y2=n-1;
        int num=1;
        while (num<=n*n)
        {
            // upper bound,  (x1, [y1,y2])
            for (size_t j = y1; j <= y2; j++)
            {
                res[x1][j] = num++;
            }
            // right, ((x1,x2], y2)
            for (size_t i = x1+1; i <=x2; i++)            
            {
                res[i][y2] = num++;
            }

            if (x1<x2 && y1<y2)
            {
                //bottom, (x2,(y2,y1))
                for (size_t j = y2-1; j >y1; j--)
                {
                    res[x2][j] = num++;
                }
                //left, ([x2,x1), y1)
                for (size_t i = x2; i >x1; i--)            
                {
                    res[i][y1] = num++;
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

