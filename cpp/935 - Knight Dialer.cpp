class Solution {
public:
    int knightDialer(int N) {
        const int mod = pow(10, 9) + 7;
        unordered_map<int, vector<int>> trans = {{0, {4, 6}}, {1, {6, 8}}, {2, {7,9}}, {3, {4, 8}}, {4, {3, 9, 0}}, {6, {7, 1, 0}}, {7, {6, 2}}, {8, {1, 3}}, {9, {2, 4}}, {0, {4, 6}}};
        
        vector<vector<int>> dp(2, vector<int>(10, 1));
        
        for(auto i{1}; i < N; ++i)
        {
            for(auto j{0}; j < 10; ++j)
            {
                auto sum{0};
                
                for(const auto& x : trans[j])
                {
                    sum += dp[~i & 1][x];
                    sum %= mod;
                }
                
                dp[i & 1][j] = sum;
            }
        }
        
        auto sum{0};
        for(auto num : dp[~N & 1])
        {
            sum += num;
            sum %= mod;
        }
        
        return sum;
    }
};