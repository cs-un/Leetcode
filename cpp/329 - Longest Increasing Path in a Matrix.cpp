class Solution {
public:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& longest, int x, int y, int prev)
    {
        if(x < 0 || x >= longest.size())
        {
            return 0;
        }
        if(y < 0 || y >= longest[0].size())
        {
            return 0;
        }
        if(prev >= matrix[x][y])
        {
            return 0;
        }
        if(longest[x][y] != -1)
        {
            return longest[x][y];
        }
        
        auto r = dfs(matrix, longest, x + 1, y, matrix[x][y]);
        auto l = dfs(matrix, longest, x - 1, y, matrix[x][y]);
        auto u = dfs(matrix, longest, x, y + 1, matrix[x][y]);
        auto d = dfs(matrix, longest, x, y - 1, matrix[x][y]);
        longest[x][y] = max(r, max(l, max(u, d))) + 1;
        return longest[x][y];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
        {
            return 0;
        }
        vector<vector<int>> longestPaths(matrix.size(), vector<int>(matrix[0].size(), -1));
        stack<vector<int>> next{};

        int mmax{0};
        
        for(auto i{0}; i < matrix.size(); ++i)
        {
            for(auto j{0}; j < matrix[0].size(); ++j)
            {
                if(longestPaths[i][j] != -1)
                {
                    continue;
                }
                
                mmax = max(mmax, dfs(matrix, longestPaths, i, j, INT_MIN));
            }
        }
        
        return mmax;
    }
};