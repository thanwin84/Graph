static bool isValidCell(vector<vector<int>>& image, int row, int col) {
    int rows = image.size();
    int cols = image[0].size();
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        return true;
    }
    return false;
}

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> copyOfGrid = grid;
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        queue<pair<pair<int, int>, int>> q;

        // push all the rotten mangoes to the queue
        int freshMangoes = 0;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 1) freshMangoes++;
                if (grid[row][col] == 2) {
                    q.push({{ row, col }, 0});
                    visited[row][col] = 1;
                }
            }
        }

        int minutes = 0;
        int rottenMangoes = 0;
        while (!q.empty()) {
            pair<pair<int, int>, int> p = q.front();
            q.pop();
            minutes = max(minutes, p.second);
            vector<vector<int>> directions = { {-1, 0}, {1, 0},{0, -1}, {0, 1} };
            for (auto & it : directions) {
                int nextRow = p.first.first + it[0];
                int nextCol = p.first.second + it[1];
                if (isValidCell(grid, nextRow, nextCol) && !visited[nextRow][nextCol] && grid[nextRow][nextCol] == 1) {
                    visited[nextRow][nextCol] = 1;
                    copyOfGrid[nextRow][nextCol] = 2;
                    q.push({{ nextRow, nextCol }, p.second + 1});
                    rottenMangoes++;
                }
            }
        }
        if (freshMangoes != rottenMangoes){
            return -1;
        }

        return minutes;
    }


};
