class Solution {
public:
    string getHint(string secret, string guess) {
        auto cows{0};
        auto bulls{0};
        
        unordered_map<char, int> freq{};
        
        for(char c : secret)
        {
            ++freq[c];
        }
        
        for(auto i{0}; i < secret.size(); ++i)
        {
            if(secret[i] == guess[i])
            {
                ++bulls;
                if(freq[secret[i]] <= 0)
                {
                    --cows;
                }
                --freq[secret[i]];
            }
            else if(guess[i] && freq[guess[i]] > 0)
            {
                ++cows;
                --freq[guess[i]];
            }
        }
        
        string output = to_string(bulls) + "A" + to_string(cows) + "B";
        
        return output;
    }
};