class Solution {
public:
    int numDecodings(string s) {
        if(s.length() == 0 || s[0] == '0')
        {
            return 0;
        }
        int dp[s.length() + 1];
        
        dp[0] = 1;
        dp[1] = 1;
        for(auto i{2}; i <= s.length(); ++i)
        {
            auto c1 = s[i-2];
            auto c2 = s[i-1];
            
            auto d1 = (c1 == '2' && c2 <= '6')  || c1 == '1' ? dp[i-2] : 0;
            auto d2 = c2 != '0' ? dp[i-1] : 0;
            dp[i] = d1 + d2;
        }
        
        return dp[s.length()];
    }
};