class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> transposed(A[0].size(), vector<int>(A.size()));
        
        for(auto i{0}; i < A.size(); ++i)
        {
            for(auto j{0}; j < A[0].size(); ++j)
            {
                transposed[j][i] = A[i][j];
            }
        }
        return transposed;
    }
};