class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans{};
        generate(string("("), 1, 0, n, &ans);
        return ans;
    }
    
    
    void generate(string s, int l, int r, int n, vector<string>* ans)
    {
        if(l < n)
        {
            generate(s + "(", l + 1, r, n, ans);
        }
        if(l > r)
        {
            generate(s + ")", l, r + 1, n, ans);
        }
        if(l == n && r == n)
        {
            ans->push_back(s);   
        }
    }
};