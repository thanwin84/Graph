import sys
sys.setrecursionlimit(10**8)
from collections import deque


def isValid(rows, cols, row, col):
    return 0 <= row < rows and 0 <= col < cols


class Solution:

    def bfs(self, grid, visited, row, col):
        q = deque()
        # mask current cell as visited
        visited[row][col] = 1
        # since current cell is visited, append it in the queue
        q.append([row, col])
        directions = [[-1, 0], [-1, 1], [0, 1], [1, 1], [1, 0], [1, -1], [0, -1], [-1, -1]]
        while q:
            current = q.popleft()
            # explore all the 8 directions
            for direction in directions:
                next_row = current[0] + direction[0]
                next_col = current[1] + direction[1]
                if isValid(len(grid), len(grid[0]), next_row, next_col) and visited[next_row][next_col] != 1 and grid[next_row][next_col] == 1:
                    visited[next_row][next_col] = 1
                    q.append([next_row, next_col])

    def numIslands(self, grid):
        rows = len(grid)
        cols = len(grid[0])
        visited = [[0 for i in range(cols)] for j in range(rows)]
        numberOfIslands = 0
        for row in range(rows):
            for col in range(cols):
                if visited[row][col] == 0 and grid[row][col] == 1:
                    numberOfIslands += 1
                    self.bfs(grid, visited, row, col)

        return numberOfIslands
