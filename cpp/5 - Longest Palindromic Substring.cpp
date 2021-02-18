class Solution {
public:
    string longestPalindrome(string s) {
        auto maxlength{1};
        string longest{s[0]};

        for(auto i{1}; i < s.length(); ++i)
        {
            vector<int> odd = getLongestPalindrome(s, i - 1, i + 1);
            vector<int> even = getLongestPalindrome(s, i - 1, i);

            auto l1 = odd[1] - odd[0];
            auto l2 = even[1] - even[0];
            vector<int> lo = l1 > l2 ? vector<int>{odd[0], odd[1]} : vector<int>{even[0], even[1]};
            if(lo[1] - lo[0] > maxlength)
            {
                longest = s.substr(lo[0], lo[1] - lo[0]);
                maxlength = lo[1] - lo[0];
            }
        }

      return longest;
    }
    
    
    vector<int> getLongestPalindrome(string &str, int leftidx, int rightidx)
    {
        for(;leftidx >= 0 && rightidx < str.length() && str[leftidx] == str[rightidx]; --leftidx, ++rightidx);
        return {leftidx + 1, rightidx};
    }
};