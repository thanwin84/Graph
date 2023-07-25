class Solution:
    def __init__(self):
        self.count = 0

    def isValid(self, grid, row, col):
        rows = len(grid)
        cols = len(grid[0])
        if 0 <= row < rows and 0 <= col < cols:
            return True
        return False

    def dfs(self, grid, visited, row, col):
        # mark as visited
        visited[row][col] = 1
        self.count += 1
        directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        for direction in directions:
            nextRow = row + direction[0]
            nextCol = col + direction[1]
            # we can move to next cell if the next cell is 1(land) and not visited
            if self.isValid(grid, nextRow, nextCol) and not visited[nextRow][nextCol] and grid[nextRow][nextCol] == 1:
                self.dfs(grid, visited, nextRow, nextCol)


    def numEnclaves(self, grid) -> int:
        rows = len(grid)
        cols = len(grid[0])
        visited = [[0 for _ in range(cols)] for _ in range(rows)]
        # checking first and last rows
        for col in range(cols):
            # checking first row
            if visited[0][col] == 0 and grid[0][col]:
                self.dfs(grid, visited, 0, col)
            # checking last row
            if visited[rows - 1][col] == 0 and grid[rows - 1][col]:
                self.dfs(grid, visited, rows - 1, col)


        # checking first column and last column
        for row in range(rows):
            # checking first column
            if visited[row][0] == 0 and grid[row][0] == 1:
                self.dfs(grid, visited, row, 0)
            # checking last column
            if visited[row][cols - 1] == 0 and grid[row][cols - 1]:
                self.dfs(grid, visited, row, cols - 1)
        totalOnes = sum([row.count(1) for row in grid])

        return totalOnes - self.count
