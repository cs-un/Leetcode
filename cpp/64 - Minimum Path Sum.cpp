class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();

        int n = grid[0].size();
        
        int sums[m][n];
        sums[0][0] = grid[0][0];
        
        for(auto j{1}; j < n; ++j)
        {
            sums[0][j] = sums[0][j-1] + grid[0][j];
        }
        
        for(auto i{1}; i < m; ++i)
        {
            sums[i][0] = sums[i-1][0] + grid[i][0];
        }
        
        for(auto i{1}; i < m; ++i)
        {
            for(auto j{1}; j < n; ++j)
            {
                sums[i][j] = min(sums[i-1][j], sums[i][j-1]) + grid[i][j];
            }
        }
        
        return sums[m-1][n-1];
    }
};