class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        
        if (root)
        {
            queue<pair<int, TreeNode*>> queue;
            queue.push(make_pair(0, root));

            while(!queue.empty())
            {
                const auto tup = queue.front();
                queue.pop();
                if (levels.size() < tup.first + 1)
                {
                    levels.push_back(vector<int>());
                }
                levels[tup.first].push_back(tup.second->val);
                if (tup.second->left)
                {
                    queue.push(pair(tup.first + 1, tup.second->left));
                }

                if (tup.second->right)
                {
                    queue.push(pair(tup.first + 1, tup.second->right));
                }
            }
        }
        
        return levels;
    }
};