class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k = 2;
        int n = prices.size();
        
        if(n == 0)
        {
            return 0;
        }
        
        vector<vector<int>> profits(k + 1, vector<int>(n, 0));
        for(int i{1}; i < k + 1; ++i){
            int m = INT_MIN;
            for(int j{1}; j < n; ++j)
            {
                m = max(m, profits[i-1][j-1] - prices[j-1]);
                profits[i][j] = max(profits[i][j-1], m + prices[j]);			
            }
        }

        return profits[k][n-1];
    }
};