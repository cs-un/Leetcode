class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(auto i{0}; i < board.size(); ++i)
        {
            for(auto j{0}; j < board[0].size(); ++j)
            {
                if(board[i][j] == word[0])
                {
                    vector<vector<bool>> visited(board.size(), vector(board[0].size(), false));
                    if(find(board, word, i, j, visited, 0))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    bool find(vector<vector<char>>& board, string word, int i, int j, vector<vector<bool>>& visited, int idx)
    {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || word[idx] != board[i][j] || visited[i][j])
        {
            return false;
        }
        if(idx == word.length() - 1)
        {
            return true;
        }
        visited[i][j] = true;
        ++idx;
        if(find(board, word, i, j + 1, visited, idx) || find(board, word, i, j - 1, visited, idx) || find(board, word, i + 1, j, visited, idx) || find(board, word, i - 1, j, visited, idx))
        {
           return true;
        }
        visited[i][j] = false;
        return false;
    }
};