bool isValidCell(int rows, int cols, int row, int col) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            return true;
        }
        return false;
    }
class Solution {
private:
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int i, int j) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> q;
        // mark current position as visited
        visited[i][j] = 1;
        q.push({ i, j });
        vector<vector<int >> directions = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };
        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();
            // explore all 8 directions
            for (auto & direction : directions) {
                int next_row = current.first + direction[0];
                int next_col = current.second + direction[1];
                // check if the next destination is already visited or not
                if (isValidCell(rows, cols, next_row, next_col) && !visited[next_row][next_col] && grid[next_row][next_col] == '1') {
                    visited[next_row][next_col] = 1;
                    q.push({ next_row, next_col });
                }
            }
        }
    }
public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int rows = grid.size();
        int cols = grid[0].size();
        // visited array to keap track of visited cell
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        int numOfIslands = 0;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == '1' && !visited[row][col]) {
                    bfs(grid, visited, row, col);
                    numOfIslands++;
                }
            }
        }
        return numOfIslands;
    }
};

//Space: O(n^2) and TC: O(n^2)[for exploring the whole grid] + O(n^2)[if the all the grid is marked as 1, then we have to search N^2 nodes for the first bfs]
