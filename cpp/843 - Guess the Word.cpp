/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int intersect(string& word1, string& word2)
    {
        auto match{0};
        
        for(auto i{0}; i < word1.size(); ++i)
        {
            if(word1[i] == word2[i])
            {
                ++match;
            }
        }
        
        return match;
    }
    
    void findSecretWord(vector<string>& wordlist, Master& master) {
        unordered_set<int> word_indexes{};
        
        for(auto i{0}; i < wordlist.size(); ++i)
        {
            word_indexes.insert(i);
        }
        
        while(!word_indexes.empty())
        {
            auto next = *word_indexes.begin();
            auto correct = master.guess(wordlist[next]);
            if(correct == wordlist[0].size())
            {
                return;
            }
            for(auto it = word_indexes.begin(); it != word_indexes.end();)
            {
                if(intersect(wordlist[*it], wordlist[next]) != correct)
                {
                    it = word_indexes.erase(it);
                }
                else
                {
                    ++it;
                }
            }
            word_indexes.erase(next);
        }
    }
};