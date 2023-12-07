# from collections import deque
def solution(edges):
    dic = {}
    dic_chosen = {}
    for i in edges:
        dic[i[0]] = dic.get(i[0], set()) | {i[1]}
        dic_chosen[i[1]] = dic_chosen.get(i[1], set()) | {i[0]}
    # O(n)
 
    for i in dic:
        if dic_chosen.get(i, 0):
            continue
        if len(dic[i]) >= 2:
            buntang = i
            break

    # O(n)

    candidates = dic[buntang]
    answer = [buntang, 0, 0, 0]
    def check(node):
        if len(dic_chosen[node]) == 1:
            return 2
        next = node

        while dic.get(next, 0):
            # next = que.popleft()
            if next in dic and len(dic[next]) > 1:
                return 3
            # while dic.get(next, 0):
            #     que.append(dic[next].pop())
            next = dic[next].pop()
        if next == node:
            return 1
        else:
            return 2


    # O(n)
    for i in candidates:
        if i in dic:
            answer[check(i)] += 1
            # val = check(i)
            # if val: 
        else:
            answer[2] += 1    
    return answer



from collections import deque
def solution(edges):
    dic = {}
    dic_chosen = {}
    max_node = 0
    for i in edges:
        dic[i[0]] = dic.get(i[0], set()) | {i[1]}
        dic_chosen[i[1]] = dic_chosen.get(i[1], set()) | {i[0]}
        max_node = max(i[0], i[1], max_node)

    for i in dic:
        if dic_chosen.get(i, 0):
            continue
        if len(dic[i]) >= 2:
            buntang = i
            break

    candidates = dic[buntang]
    answer = [buntang, 0, 0, 0]
    def check(node):
        version = 1
        next = node
        que = deque()
        que.append(next)
        while que:
            next = que.popleft()
            print('next는', next)
            if next in dic and len(dic[next]) > 1:
                version = 3
            while dic.get(next, 0):
                que.append(dic[next].pop())


        if version == 3:
            return 3
        if next == node:
            return 1
        elif dic_chosen.get(i, 0):
            return 2

    print(dic)

    for i in candidates:
        if i in dic:
            val = check(i)
            print(i, '의 답은 ', val)
            if val: answer[val] += 1
        else:
            answer[2] += 1
        print(dic)


    return answer