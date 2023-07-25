from collections import deque

class Solution:
    def __init__(self):
        # count 1s that are connect with boundary 1
        self.count = 0

    def isValid(self, grid, row, col):
        rows = len(grid)
        cols = len(grid[0])
        if 0 <= row < rows and 0 <= col < cols:
            return True
        return False

    def bfs(self, grid, visited, row, col):
        q = deque()
        q.append([row, col])
        visited[row][col] = 1
        directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        while len(q) != 0:
            current = q.popleft()
            self.count += 1
            # explore four direction
            # we can only go to next cell if the next cell is a land(1) and not visited
            for direction in directions:
                nextRow = current[0] + direction[0]
                nextCol = current[1] + direction[1]
                if self.isValid(grid, nextRow, nextCol) and not visited[nextRow][nextCol] and grid[nextRow][
                    nextCol] == 1:
                    q.append([nextRow, nextCol])
                    # since we can to next cell, mark next cell as visited
                    visited[nextRow][nextCol] = 1

    def numEnclaves(self, grid) -> int:
        rows = len(grid)
        cols = len(grid[0])
        visited = [[0 for _ in range(cols)] for _ in range(rows)]
        # checking first and last rows
        for col in range(cols):
            if visited[0][col] == 0 and grid[0][col]:
                self.bfs(grid, visited, 0, col)
            if visited[rows - 1][col] == 0 and grid[rows - 1][col]:
                self.bfs(grid, visited, rows - 1, col)

        # checking first column and last column
        for row in range(rows):
            if visited[row][0] == 0 and grid[row][0] == 1:
                self.bfs(grid, visited, row, 0)
            if visited[row][cols - 1] == 0 and grid[row][cols - 1]:
                self.bfs(grid, visited, row, cols - 1)
        totalOnes = sum([row.count(1) for row in grid])

        return totalOnes - self.count
