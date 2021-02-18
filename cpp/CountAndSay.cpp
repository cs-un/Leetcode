class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
        {
            return "1";
        }
        else
        {
            string prev = countAndSay(n-1);
            string ret = "";
            auto curr = 1;
            for (auto i{1}; i < prev.size(); ++i)
            {
                if(prev[i] == prev[i-1])
                {
                    ++curr;
                }
                else
                {
                    ret += to_string(curr);
                    ret += prev[i-1];
                    curr = 1;
                }
            }
            ret += to_string(curr);
            ret += prev[prev.size() - 1];
            return ret;
        }
    }
};