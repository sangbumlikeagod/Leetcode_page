
class Solution:
    def connect(self, root):
        from queue import Queue
        lst = Queue()
        if not root:
            return None
        def recur(root, idx):
            
            if root.left:
                lst.put((root.left ,idx + 1))
            if root.right: 
                lst.put((root.right, idx + 1))
            if not lst.empty():
                next = lst.get()
                if next[1] == idx:
                    root.next = next[0]
                else:
                    root.next =  None
                recur(next,  idx + 1)
            else: return
             
        recur(root, 1)
        return root

