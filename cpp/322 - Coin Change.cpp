class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for(auto i{1}; i <= amount; ++i)
        {
            for(const auto j : coins)
            {
                if (i >= j)
                {
                    dp[i] = min(dp[i], dp[i-j] + 1);
                }
            }
        }
        
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};