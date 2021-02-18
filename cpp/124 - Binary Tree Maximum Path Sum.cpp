class Solution {
public:
    int max_sum = INT_MIN;
    
    int maxPathSum(TreeNode* root) {
        maxPathSumHelp(root);
        return max_sum;
    }
    
    int maxPathSumHelp(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        const auto left = maxPathSumHelp(root->left);
        const auto right = maxPathSumHelp(root->right);
        auto sum = left + right + root->val;
        max_sum = max(sum, max_sum);
        return max(0, root->val + max(left, right));
    }
};