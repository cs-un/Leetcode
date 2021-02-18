class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length() == 0)
        {
            return true;
        }
        bool allcaps = word[0] >= 'A' && word[0] <= 'Z';
        bool firstCaps = allcaps;
        bool lowercase = !allcaps;
        for (auto i{1}; i < word.length(); ++i)
        {
            if(word[i] >= 'A' && word[i] <= 'Z')
            {
                firstCaps = false;
                lowercase = false;
            }
            else
            {
                allcaps = false;
            }
        }
        return allcaps || firstCaps || lowercase;
    }
};