

import sys
file = open('1260.txt')
sys.stdin = file
node, edge, start = map(int,input().split())

dic = {}
for i in range(edge):
    a, b = map(int, input().split())
    dic[a] = dic.get(a, []) + [b]
    dic[b] = dic.get(b, []) + [a]
print(dic)
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
    if not queue:
        return
    course = queue.pop(0)
    bfs(course)
    
bfs(start)