class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<string, char> mapping{};
        unordered_set<char> mapped{};
        stringstream ss{str};
        auto i{0};
        string word;
        while(getline(ss, word, ' '))
        {
            if(mapping.count(word))
            {
                if(pattern[i] != mapping[word])
                {
                    return false;
                }
                ++i;
            }
            else if(!mapped.count(pattern[i]))
            {
                mapping[word] = pattern[i];
                mapped.insert(pattern[i]);
                ++i;
            }
            else
            {
                break;
            }
        }
        
        return i == pattern.size();
    }
};