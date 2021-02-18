class Solution {
public:
    int paint(TreeNode* node, int& count)
    {
        if(!node)
        {
            return -1;
        }
        int left = paint(node->left, count);
        int right = paint(node->right, count);
        
        if(!left || !right)
        {
            ++count;
            return 1;
        }
        else if(left == 1 || right == 1)
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }
    
    int minCameraCover(TreeNode* root) {
        int count = 0;
        int state = paint(root, count);
        count += state == 0;
        return count;
    }
};