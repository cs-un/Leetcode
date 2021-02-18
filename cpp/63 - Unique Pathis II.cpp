class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid[0].size();
        int m = obstacleGrid.size();
        if(m == 0 || n == 0)
        {
            return 0;
        }

        vector<vector<long>> paths(m, vector<long>(n, 0));
        bool blocked = false;
        for (int j = 0; j < n; ++j)
        {
            if(!blocked)
            {
                blocked = obstacleGrid[0][j] == 1;
            }
            paths[0][j] = blocked ? 0 : 1;
        }
        blocked = false;
        for (int i = 0; i < m; ++i)
        {
            if(!blocked)
            {
                blocked = obstacleGrid[i][0] == 1;
            }
            paths[i][0] = blocked ? 0 : 1;
        }
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                if(obstacleGrid[i][j] == 1)
                {
                    continue;
                }
                paths[i][j] = paths[i][j - 1] + paths[i-1][j];
            }
        }
        
        return paths[m-1][n-1];
    }
};