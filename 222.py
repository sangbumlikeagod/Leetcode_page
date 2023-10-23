class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        def dfs(node):
            if node == None:
                return 0
            
            return dfs(node.left) + dfs(node.right) + 1
        
        return dfs(root)