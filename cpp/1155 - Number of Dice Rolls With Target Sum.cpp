class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int mod{(int)pow(10, 9) + 7};
        int sums[d+1][target+1]{0};
        for(int j{0}; j < target; ++j)
        {
            sums[0][j] = 0; 
        }
        sums[0][0] = 1;
        for(int i{1}; i <= d; ++i)
        {
            for(int j{1}; j <= target; ++j)
            {
                for(int x{1}; x <= f; ++x)
                {
                    if (x <= j)
                    {
                        sums[i][j] = (sums[i-1][j-x] + sums[i][j]) % mod;
                    }
                }
            }
        }
        
        return sums[d][target];
    }
};