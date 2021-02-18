class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
        {
            return 0;
        }
        const int needleLength{needle.length()};
        const int haystackLength{haystack.length()};
        
        auto j{0};
        for (auto i{0}; i <= haystackLength - needleLength; ++i)
        {
            for(j = 0; j < needleLength && haystack[i + j] == needle[j]; ++j);
            
            if (j == needleLength)
            {
                return i;
            }
        }
        return -1;
    }
};