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

        
        letsgo = [ [ i for i in kak ] for kak in mat ]
        overlap = [[0] * size_column for _ in range(size_row)]
        
        def search(node):
            if mat[node[0]][node[1]] == 0:
                return 0
            min = 10000
            overlap[node[0]][node[1]] = 1
            can_go = [[node[0] + i[0], node[1] + i[1]] for i in [[0,1], [0, -1], [1, 0], [-1, 0]] \
                      if 0 <= node[0] + i[0] < size_row \
                      if 0 <= node[1] + i[1] < size_column
                      ]
            for i in can_go:
                if not overlap[i[0]][i[1]]:
                    ice = search(i) 
                    if ice < min:
                        min = ice

            return min + 1
        
        for i in range(size_row):
            for j in range(size_column):
                letsgo[i][j] = search([i, j])

        return letsgo
a = Solution()
# print(a.updateMatrix([[0,0,0],[0,1,0],[1,1,1]]))
# print(a.updateMatrix([[0,0,0],[0,1,0],[0,0,0]]))
# print(a.updateMatrix([[0,1,0],[0,1,0],[0,1,0],[0,1,0],[0,1,0]]))
# print(a.updateMatrix([[0,0,1,0,1,1,1,0,1,1],[1,1,1,1,0,1,1,1,1,1],[1,1,1,1,1,0,0,0,1,1],[1,0,1,0,1,1,1,0,1,1],[0,0,1,1,1,0,1,1,1,1],[1,0,1,1,1,1,1,1,1,1],[1,1,1,1,0,1,0,1,0,1],[0,1,0,0,0,1,0,0,1,1],[1,1,1,0,1,1,0,1,0,1],[1,0,1,1,1,0,1,1,1,0]]))
# print(a.updateMatrix([[0,1,0,1,1],
#                       [1,1,0,0,1],
#                       [0,0,0,1,0],
#                       [1,0,1,1,1],
#                       [1,0,0,0,1]]))
print(a.updateMatrix([[0,0,0,1,1,1,1,1,0]]))

# 조까 