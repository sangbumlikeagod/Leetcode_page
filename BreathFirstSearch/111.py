from queue import Queue

a = Queue()
a.put(3)
a.put(5)
print(a.get())
print(a.qsize())




def bfs(root, queue, layer):
    size = queue.qsize()
    if root.left:
        queue.put((root.left, layer))
    if root.right:
        queue.put((root.right, layer))

    if queue.qsize() == size:
        return layer
    else:
        new_root, new_layer = queue.get()
        bfs(new_root, queue, new_layer)

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


root = TreeNode(3)
r_1 = TreeNode(9)
r_2 = TreeNode(20)
r_3 = TreeNode(15)
r_4 = TreeNode(7)
root.left = r_1
root.right = r_2
r_2.left = r_3
r_2.right = r_4


class Solution:
    def minDepth(self, root) -> int:
        def bfs(root, queue, layer):
            print(queue.qsize(), layer)
            size = queue.qsize()
            if root.left:
                print('도달')
                queue.put((root.left, layer + 1))
            if root.right:
                queue.put((root.right, layer + 1))
            print(queue.qsize(), size)
            if queue.qsize() == size:
                print('벌써 끝', layer)
                return layer
            else:
                new_root, new_layer = queue.get()
                print(new_root, new_layer)
                return bfs(new_root, queue, new_layer)
        new_queue = Queue()
        result = bfs(root, new_queue, 1)
        print(result)
        return result
    
a = Solution(
)
a.minDepth(root)


# goat 의 풀이


class Solution:
    def minDepth(self,root)->int:
        if not root:
            return 0

        if not root.left and not root.right:
            return 1

        left=self.minDepth(root.left) if root.left else float('inf')
        right=self.minDepth(root.right) if root.right else float('inf')

        return 1+min(left,right)            


import heapq