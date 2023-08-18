
import sys
sys.setrecursionlimit(10000)
class Solution:
    def updateMatrix(self, mat ):
        size_row = len(mat)
        size_column = len(mat[0])
        idx = [0, 0]
        # for i in range(size_row):
        #     for j in range(size_column):
        #         if mat[i][j]:
        #             idx = [i, j]
        #             break
        from collections import deque
        que = deque()
        
        result = [[0] * size_column for _ in range(size_row)]
        result = [_[:] for _ in mat]

        overlap = [[0] * size_column for _ in range(size_row)]
        conclude = [[0] * size_column for _ in range(size_row)]
        
        def searbch(node):
            # print(node)
            # overlap[node[0]][node[1]] = 1
            candidates = [[node[0] + i[0], node[1] + i[1]] for i in [[0,1], [0, -1], [1, 0], [-1, 0]] \
                      if 0 <= node[0] + i[0] < size_row \
                      if 0 <= node[1] + i[1] < size_column \

                      ]
            for candidate in candidates:
                if not overlap[candidate[0]][candidate[1]]:
                    overlap[candidate[0]][candidate[1]] = 1
                    que.append(candidate)
            if que:
                searbch(que.popleft())

            if mat[node[0]][node[1]]:
                # print(result, node, candidates)
                candidates = [result[candidate[0]][candidate[1]] for candidate in candidates if conclude[candidate[0]][candidate[1]]]
                if candidates:
                    result[node[0]][node[1]] = min(candidates) + 1
                    conclude[node[0]][node[1]] = 1
            else: 
                result[node[0]][node[1]] = 0
                conclude[node[0]][node[1]] = 1

        overlap = [[0] * size_column for _ in range(size_row)]

        switch = True
        while switch:
            switch = False
            for i in range(size_row):
                for j in range(size_column):
                    prev = result[i][j]
                    searbch([i, j])
                    if prev != result[i][j]:
                        switch = True
            if switch == False:
                break

                    
        return result

a = Solution()
print(a.updateMatrix([[0,0,0],[0,1,0],[1,1,1]]))
# print(a.updateMatrix([[0,0,0],[0,1,0],[0,0,0]]))
# print(a.updateMatrix([[0,1,0],[0,1,0],[0,1,0],[0,1,0],[0,1,0]]))
print(a.updateMatrix([[0,0,1,0,1,1,1,0,1,1],[1,1,1,1,0,1,1,1,1,1],[1,1,1,1,1,0,0,0,1,1],[1,0,1,0,1,1,1,0,1,1],[0,0,1,1,1,0,1,1,1,1],[1,0,1,1,1,1,1,1,1,1],[1,1,1,1,0,1,0,1,0,1],[0,1,0,0,0,1,0,0,1,1],[1,1,1,0,1,1,0,1,0,1],[1,0,1,1,1,0,1,1,1,0]]))
print(a.updateMatrix([[0,1,0,1,1],
                      [1,1,0,0,1],
                      [0,0,0,1,0],
                      [1,0,1,1,1],
                      [1,0,0,0,1]]))
print(a.updateMatrix([[0,0,0,1,1,1,1,1,0]]))
