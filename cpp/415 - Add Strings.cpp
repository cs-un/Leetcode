class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        string res{};
        auto carry{0};
        for(auto i{n1 - 1}, j{n2 - 1}; i >= 0 || j >= 0; --i, --j)
        {
            auto sum{carry};
            carry = 0;
            if(i >= 0)
            {
                sum+=num1[i] - '0';
            }
            if(j >= 0)
            {
                sum+=num2[j] - '0';
            }
            if(sum > 9)
            {
                carry = 1;
                sum%=10;
            }
            res.append(to_string(sum));
        }
        if(carry)
        {
            res.append(to_string(carry));
        }
        return {res.rbegin(), res.rend()};
    }
};