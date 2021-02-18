class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        queue<int> path{};
        auto next = root;
        
        while(next != p)
        {
            if(p->val < next->val)
            {
                next = next->left;
            }
            else
            {
                next = next->right;
            }
            path.push(next->val);
        }
        
        next = root;
        
        while(next != q)
        {
            auto nextStop{path.front()};
            path.pop();
            if(q->val < next->val)
            {
                if(nextStop != next->left->val)
                {
                    return next;
                }
                next = next->left;
            }
            else
            {
                if(nextStop != next->right->val)
                {
                    return next;
                }
                next = next->right;
            }
        }
        return q;
    }
};