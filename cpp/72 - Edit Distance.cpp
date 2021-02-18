class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size() + 1;
        int n = word2.size() + 1;
        vector<vector<int>> dists(m, vector<int>(n, 0));

        for(auto i{1}; i < m; ++i)
        {
            dists[i][0] = i;
        }

        for(auto i{1}; i < n; ++i)
        {
            dists[0][i] = i;
        }

        for(auto i{1}; i < m; ++i)
        {
            for(auto j{1}; j < n; ++j)
            {
                if(word1[i - 1] == word2[j - 1])
                {
                    dists[i][j] = dists[i-1][j-1];
                }
                else
                {
                    dists[i][j] = min(dists[i-1][j], min(dists[i][j-1], dists[i-1][j-1])) + 1;
                }
            }
        }

      return dists[m-1][n-1];
    }
};