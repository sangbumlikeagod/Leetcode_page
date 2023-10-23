
'''

트리의 구현

'''

tree = list(range(7))
print(tree)

i = 1
def tree_search(num):
    global i
    if num * 2 < len(tree):
        tree_search(num * 2)
    tree[num] = i
    i += 1
    if num * 2 + 1 < len(tree):
        tree_search(num * 2 + 1)


tree_search(1)
print(tree)


#리스트를 통한 트리의 구현

'''

연결리스트를 통한 완전이진트리의 구성 

'''

class Tree:
    def __init__(self) -> None:
        self.root = None
        self.queue = []
        
    def put(self, root, node):
        # print(node.val)
        if not root.left:
            root.left = node
            return True
        if not root.right:
            root.right = node
            return True
        self.queue.append(root.left)
        self.queue.append(root.right)
        self.put(self.queue.pop(0), node)
        
        return False
        
class Listnode:
    def __init__(self, val) -> None:
        self.val = val
        self.left = None
        self.right = None        
root = Listnode(1)
tree = Tree()
tree.root = root
for i in range(2, 7):
    tree.put(root, Listnode(i))
    
def recur(node):
    if not node:
        return
    print(node.val, end = ' ')
    recur(node.left)
    recur(node.right)
# print(root.left.right.val, root.right.val)
recur(root)