
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
# lst=0
# def changeTree(node,lst):
#     for i in lst:
#         pass

# table={}

# # def recur(lst,i):
# #     if i == len(lst):
# #         return False
#     if i==0:
#         table[i]=TreeNode(lst[i])
#         recur(lst,i+1)
#     if i-1 in table:
            
#         if i%2==1:
#             table[i]=TreeNode(lst[i])
#             table[i-1//2].left=table[i]
#         else: 
#             table[i]=TreeNode(lst[i])
#             table[i-1//2].right=table[i]
        
#     recur(lst,i+1)

# nodeValues=[]
# def dfs(node):
#     if node is None:
#         return
#     nodeValues.append(node.val)
#     dfs(node.left)
#     dfs(node.right)
        
        
lst=[4,2,6,1,3]

class Solution:
    def getMinimumDifference(self, root):
        def recur(node,prevnode=None):
            if node.val==None:
                return None
            a=recur(node.left,node)
            b=recur(node.right,node)
            if prevnode:
                c=abs(node.val-prevnode.val)
                
            else: c=None
            
            lst=[]
            for i in [a,b,c]:
                if i is not None:
                    lst.append(i)
                    
            return min(lst)

        return recur(root)
                
                
                