class Solution {
public:
    bool validate(TreeNode* root, long left, long right)
    {
        if(!root)
        {
            return true;
        }
        
        if(root->val > left && root->val < right)
        {
            return validate(root->left, left, root->val) && validate(root->right, root->val, right);
        }
        
        return false;
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root)
        {
            return true;
        }
        
        return validate(root->left, (long)INT_MIN - 1, root->val) && validate(root->right, root->val, (long)INT_MAX + 1);
    }
};