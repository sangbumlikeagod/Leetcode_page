class Solution:
    def getMinimumDifference(self, root):
        self.prevnode=None
        self.min_d=None
        def recur(node):
            if node==None:
                return
            recur(node.left)
            print('왼쪽으로 한칸 이동')
            
            if self.prevnode is not None:
                self.min_d=min(self.min_d,abs(self.prevnode.val-node.val))
            self.prevnode.val=node.val

            
            recur(node.right)
            print('오른쪽으로 한 칸 이동')
            
        recur(root)
        return self.min_d