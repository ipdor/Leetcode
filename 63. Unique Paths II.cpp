//https://leetcode.com/problems/unique-paths-ii/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        if(obstacleGrid[0][0] == 1)
            return 0;
        for (size_t i = 0; i < obstacleGrid.size(); i++)
        {
            for (size_t j = 0; j < obstacleGrid[0].size(); j++)
            {
                if(i==0 && j==0)
                {
                    obstacleGrid[i][j] = 1;
                    continue;
                }    
                if (obstacleGrid[i][j] == 1 )
                {
                    obstacleGrid[i][j] = 0;
                    continue;
                }
                else if (i==0)
                    obstacleGrid[i][j] = obstacleGrid[i][j-1];
                else if (j==0)
                    obstacleGrid[i][j] = obstacleGrid[i-1][j];
                else
                    obstacleGrid[i][j] = obstacleGrid[i][j-1]+ obstacleGrid[i-1][j];
            }
        }

        // for (size_t i = 0; i < obstacleGrid.size(); i++)
        // {
        //     for (size_t j = 0; j < obstacleGrid[0].size(); j++)
        //     cout<< obstacleGrid[i][j] << " ";
        // cout<< endl;
        // }
        return obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};