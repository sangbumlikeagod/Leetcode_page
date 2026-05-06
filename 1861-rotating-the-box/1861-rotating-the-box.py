class Solution:
    def rotateTheBox(self, boxGrid: List[List[str]]) -> List[List[str]]:
        m = len(boxGrid)
        n = len(boxGrid[0])
        
        answer = [['.' for i in range(m)] for j in range(n)]
        
        counts = [0] * m
        
        for i in range(m):
            for j in range(n):
                if boxGrid[i][j] == '#':
                    counts[i] += 1
                elif boxGrid[i][j] == '*':
                    answer[j][m - i - 1] = '*'
                    for k in range(j - 1, j - 1 - counts[i], -1):
                        answer[k][m - i - 1] = '#'
                    counts[i] = 0
        
        
        for i in range(m):
            for k in range(n - 1, n - 1 - counts[i], -1):
                answer[k][m - i - 1] = '#'
            
            
            
        return answer
        
    