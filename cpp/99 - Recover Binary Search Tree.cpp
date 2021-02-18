/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root, TreeNode*& min, TreeNode*& max, int& val)
    {
        if(!root)
        {
            return;
        }
        
        helper(root->left, min, max, val);
        
        if(val > root->val)
        {
            max = root;
        }
        if(!max)
        {
            min = root;
        }
        val = root->val;
            
        helper(root->right, min, max, val);
    }
    
    void recoverTree(TreeNode* root) {
        int x = INT_MIN;
        TreeNode* min = NULL;
        TreeNode* max = NULL;
        helper(root, min, max, x);
        
        auto t = min->val;
        min->val = max->val;
        max->val = t;
    }
};