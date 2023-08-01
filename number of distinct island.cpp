bool isValid(vector<vector<int>>& grid, int row, int col) {
    int rows = grid.size();
    int cols = grid[0].size();
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        return true;
    }
    return false;
}
class Solution {
public:
    set<vector<pair<int, int>>> s;
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int row, int col, int brow, int bcol, vector<pair<int, int>>& result) {
        visited[row][col] = 1;
        result.push_back({ row - brow, col - bcol });
        vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto& direction : directions) {
            int nextRow = row + direction[0];
            int nextCol = col + direction[1];
            if (isValid(grid, nextRow, nextCol) && grid[nextRow][nextCol] == 1 && !visited[nextRow][nextCol]) {
                dfs(grid, visited, nextRow, nextCol, brow, bcol, result);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 1 && !visited[row][col]) {
                    vector<pair<int,int>> result;
                    dfs(grid, visited, row, col, row, col,result);
                    s.insert(result);
                }
            }
        }
        return s.size();
    }
};

// space: O(n * m)
// tc: for dfs O(n * m) * 4 + outer loop O(n * m) * O(log n * m) = O(n * m)
