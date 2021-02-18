class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(S > 1000)
        {
            return 0;
        }
        vector<int> dp(2001, 0);
        vector<int> temp(2001);
        
        dp[1000] = 1;
        
        for(const auto& num : nums)
        {
            fill(temp.begin(), temp.end(), 0);
            for(auto j{0}; j <= 2000; ++j)
            {
                if(dp[j])
                {
                   temp[j + num] += dp[j];
                   temp[j - num] += dp[j];
                }
            }
            dp = temp;
        }
        
        return dp[S + 1000];
    }
};