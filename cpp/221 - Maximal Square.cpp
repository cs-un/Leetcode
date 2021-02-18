class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0)
        {
            return 0;
        }
        int n = matrix[0].size();
        if(n == 0)
        {
            return 0;
        }
        int dp[m][n];
        int maxval{0};
        for(auto i{0}; i < m; ++i)
        {
            for(auto j{0}; j < n; ++j)
            {
                if(matrix[i][j] == '1')
                {
                    dp[i][j] = 1;
                    maxval = 1;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        
        for(auto i{1}; i < m; ++i)
        {
            for(auto j{1}; j < n; ++j)
            {
                if(dp[i][j])
                {
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    maxval = max(maxval, dp[i][j]);
                }
            }
        }
        return maxval*=maxval;
    }
};