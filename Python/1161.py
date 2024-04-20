class Solution:
    def maxLevelSum(self, root):
        table={}
        def recur(node,level):
            if node==None:
                return
            
            if level not in table:
                table[level]=node.val
            else:
                table[level]+=node.val
            
            recur(node.left,level+1)
            recur(node.right,level+1)

        recur(root,1)
        ans=1
        for i in range(2,len(table)-1):
            ans=i if table[i]>table[ans] else ans
        return ans
    