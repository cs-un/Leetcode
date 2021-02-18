class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;
        
        words.insert(wordList.begin(), wordList.end());
        
        if(!words.count(endWord))
        {
            return 0;
        }
        words.insert(beginWord);
        
        unordered_map<string, vector<string>> validTransitions{};
        
        for(const auto &word : words)
        {
            validTransitions[word] = {};
            for(auto i{0}; i < word.length(); ++i)
            {
                for(auto c{0}; c < 26; ++c)
                {
                    auto t = word;
                    t[i] = 'a' + c;
                    if(t != word)
                    {
                        if(words.count(t))
                        {
                            validTransitions[word].push_back(t);
                        }
                    }
                }
            }
        }
        
        queue<pair<string, int>> next{};
        next.push({beginWord, 0});
        unordered_set<string> visited{};
        
        while(!next.empty())
        {
            const auto item = next.front();
            next.pop();

            if(visited.count(item.first))
            {
                continue;
            }
            
            if(item.first == endWord)
            {
                return item.second + 1;
            }
            
            const auto &transitions = validTransitions[item.first];
            
            for(const auto &trans : transitions)
            {
                next.push({trans, item.second + 1});
            }
            visited.insert(item.first);
        }
        
        return 0;
    }
};