class Solution {
public:
    
    int sum(TreeNode* root, bool left)
    {
        if(!root)
        {
            return 0;
        }
        if(!root->left && !root->right && left)
        {
            return root->val;
        }
        return sum(root->left, true) + sum(root->right, false);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        return sum(root, false);
    }
};