class Solution {
    
    struct Trie
    {
        char val;
        bool terminal;
        Trie* children[26];
    };

private:
    void dfs(vector<vector<char>>& board, int i, int j, unordered_set<string>& found, Trie* node, string& so_far, vector<vector<bool>>& visited)
    {
        if(i >= board.size() || j >= board[0].size() || i < 0 || j < 0 || visited[i][j])
        {
            return;
        }
        
        auto c = board[i][j];

        so_far+=c;
        
        auto curr = node->children[c - 'a'];
        if(curr == NULL)
        {
            so_far.pop_back();
            return;
        }
        if(curr->terminal)
        {
            found.insert(so_far);
        }
        visited[i][j] = true;

        dfs(board, i - 1, j, found, curr, so_far, visited);
        dfs(board, i + 1, j, found, curr, so_far, visited);
        dfs(board, i, j - 1, found, curr, so_far, visited);
        dfs(board, i, j + 1, found, curr, so_far, visited);
        
        so_far.pop_back();
        
        visited[i][j] = false;
    }
    
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root = new Trie();
        root->val = '_';
        for(const auto word : words)
        {
            Trie* curr = root;
            for(auto i{0}; i < word.size(); ++i)
            {
                if(curr->children[word[i] - 'a'] != NULL)
                {
                    curr = curr->children[word[i] - 'a'];
                }
                else
                {
                    Trie* temp = new Trie();
                    temp->val = word[i];
                    curr->children[word[i] - 'a'] = temp;
                    curr = temp;
                }
            }
            curr->terminal = true;
        }
        
        unordered_set<string> found{};
        
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        
        for(auto i{0}; i < board.size(); ++i)
        {
            for(auto j{0}; j < board[0].size(); ++j)
            {
                string curr{};
                dfs(board, i, j, found, root, curr, visited);
            }
        }
        
        return {found.begin(), found.end()};
    }
};