class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common{};
        if(strs.size() == 0)
        {
            return common;
        }
        auto curr = strs[0][0];
        for(auto i{0}; i < strs[0].length(); ++i, curr = strs[0][i])
        {
            for(const auto& s : strs)
            {
                if(s.length() <= i || s[i] != curr)
                {
                    return common;
                }
            }
            common+=curr;
        }
        return common;
    }
};