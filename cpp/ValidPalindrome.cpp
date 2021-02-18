class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0, x = s.size() - 1; i < x; ++i, --x)
        {
            while (i < x && !(isalpha(s[i]) || isdigit(s[i])))
            {
                ++i;
            }
            while (x > i && !(isalpha(s[x]) || isdigit(s[x])))
            {
                --x;
            }
            if (tolower(s[i]) != tolower(s[x]))
            {
                return false;
            }
        }
        return true;
    }
};