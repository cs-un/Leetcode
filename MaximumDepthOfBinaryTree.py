class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        return self.traverse(root, 0)
        
    def traverse(self, root, d):
        if root == None:
            return d
        return max(self.traverse(root.left, d + 1), self.traverse(root.right, d + 1))