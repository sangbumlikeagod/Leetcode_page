

import sys
sys.setrecursionlimit(10000)
file = open('1260.txt')
sys.stdin = file
node, edge, start = map(int,input().split())

dic = {}
for i in range(edge):
    a, b = map(int, input().split())
    if b not in dic.get(a, []):
        dic[a] = dic.get(a, []) + [b]
        dic[b] = dic.get(b, []) + [a]

for i in dic:
    dic[i].sort()

overlap = [0] * node
def dfs(node):
    print(node, end=' ')
    overlap[node - 1] = 1
    for course in dic[node]:
        if not overlap[course - 1]:
            overlap[course - 1] = 1
            dfs(course)
if start not in dic:
    print(start)
else:
    dfs(start)
print()
overlap = [0] * node
queue = []
def bfs(node):
    
    print(node, end=' ')
    overlap[node - 1] = 1
    for course in dic[node]:
        if not overlap[course - 1]:
            overlap[course - 1] = 1
            queue.append(course)
    print(queue)
    if not queue:
        return
    course = queue.pop(0)
    bfs(course)
    
if start not in dic:
    print(start)
else:
    bfs(start)