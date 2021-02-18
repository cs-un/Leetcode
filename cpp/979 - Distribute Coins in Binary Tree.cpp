class Solution {
public:
    int redistribute(TreeNode* node, int& moves)
    {
        if(!node)
        {
            return 0;
        }
        
        int left = redistribute(node->left, moves);
        int right = redistribute(node->right, moves);
        int sum = node->val - 1;
        sum += left;
        sum += right;
        moves += abs(left) + abs(right);
        return sum;
    }
    
    int distributeCoins(TreeNode* root) {
        int moves{0};
        redistribute(root, moves);
        return moves;
    }
};