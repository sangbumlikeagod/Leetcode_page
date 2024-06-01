class Solution:
    def rotate(self, matrix: list[list[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        N = len(matrix)
        
        def move(o1, o2, o3, o4):
            print(o1, o2, o3, o4)
            # print(o1)
            k = 0
            sep = o2[1] - o1[1]
            if sep < 1:
                return
            while k < sep:
                # print(k)
                # print(*matrix, sep='\n')
                # print()
                matrix[o1[0]][o1[1] + k], matrix[o2[0] + k][o2[1]], matrix[o3[0]][o3[1] - k], matrix[o4[0] - k][o4[1]] = matrix[o4[0] - k][o4[1]], matrix[o1[0]][o1[1] + k], matrix[o2[0] + k][o2[1]], matrix[o3[0]][o3[1] - k]
                k += 1
            move((o1[0] + 1, o1[1] + 1), (o2[0] + 1, o2[1] - 1), (o3[0] - 1, o3[1] - 1), (o4[0] - 1, o4[1] + 1))
        move((0, 0), (0, N - 1), (N - 1, N - 1), (N - 1, 0) )
        return matrix
                
matrix = [[1,2,3],[4,5,6],[7,8,9]]
a = Solution()
print(a.rotate(matrix))

# 알고리즘은 있음 
'''

N by N 행렬의 껍질에 대해서 
N - 1칸만큼 이동한다.


N - 2, N - 2 행렬로 이동 
4개의 칸은 각각
+1 +1 , +1 -1, -1 +1 , -1 -1 만큼씩 이동 

'''