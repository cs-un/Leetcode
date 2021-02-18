class StreamChecker {
public:
    struct Node{
        bool end;
        Node* children[26];
    };

    queue<Node*> paths{};
    Node* root;
    
    StreamChecker(vector<string>& words) {
        root = new Node{};
        for(const auto w : words)
        {
            auto curr = root;
            for(auto c : w)
            {
                if(!curr->children[c - 'a'])
                {
                    Node* node = new Node{};
                    curr->children[c - 'a'] = node;
                }
                curr = curr->children[c - 'a'];
            }
            curr->end = true;
        }
    }
    
    bool query(char letter) {
        bool found{false};
        
        paths.push(root);
        auto numPaths = paths.size();
        
        for(auto i{0}; i < numPaths; ++i)
        {
            auto node = paths.front();
            paths.pop();
            auto next = node->children[letter - 'a'];
            if(next)
            {
                paths.push(next);
                if(next->end)
                {
                    found = true;
                }
            }
        }
        
        return found;
    }
};
