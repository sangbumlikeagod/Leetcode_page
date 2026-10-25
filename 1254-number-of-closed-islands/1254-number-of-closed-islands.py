class Solution:
    
    
    def dfs(self, x, y, tracable = False) -> bool:

        ret = True
        if (x == 1 and y == 5):
            tracable = True

        # if tracable:
        #     print(x, y)
        for i in range(4):
            nx = x + self.dx[i]
            ny = y + self.dy[i]


 


            if (0 <= nx and nx < self.X) and \
                (0 <= ny and ny < self.Y) and \
                self.grid[nx][ny] == 0 and \
                self.visited[nx][ny] == 0:
                # if tracable:
                    # print('\t', x, y, nx, ny)
                self.visited[nx][ny] = 1
                ret = (self.dfs(nx, ny, tracable) and ret)

        if x == 0 or x == self.X - 1:
            # print(x, y, "edge")
            return False
        if y == 0 or y == self.Y - 1:
            # print(x, y, "edge y")
            return False

        return ret        


    def closedIsland(self, grid: list[list[int]]) -> int:
        self.grid = grid
        self.dx = [0, 0, -1, 1]
        self.dy = [-1, 1, 0, 0]
        self.X = len(grid)
        self.Y = len(grid[0])
        self.visited = [[0] * self.Y for i in range(self.X)]
        answer = 0
        
        for i in range(self.X):
            for j in range(self.Y):
                if  self.grid[i][j] == 0 and \
                    self.visited[i][j] == 0:
                    self.visited[i][j] = 1
                    if self.dfs(i, j):
                        # print(i, j)
                        answer += 1
        return answer