class Solution {
public:
    bool isValidCell(vector<vector<char>>& mat, int row, int col) {
        int rows = mat.size();
        int cols = mat[0].size();
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            return true;
        }
        return false;
    }
    void dfs(vector<vector<char>>& mat, int row, int col, vector<vector<int>>& visited) {
        // mark it as visited
        visited[row][col] = 1;
        // conver 0 to X
        vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0,-1}, {0, 1} };
        // explore all four directions
        // we can go to next cell if it's 0,cause we need to mark all connection 0 to X
        for (auto &direction : directions) {
            int nextRow = direction[0] + row;
            int nextCol = direction[1] + col;
            if (isValidCell(mat, nextRow, nextCol) && !visited[nextRow][nextCol] && mat[nextRow][nextCol] == 'O') {
                dfs(mat, nextRow, nextCol, visited);
            }

        }
    }
    vector<vector<char>> fill(int rows, int cols, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> visited(rows, vector<int>(cols, 0));

        // treverse frist row and last row
        for (int j = 0; j < cols; j++) {
            // first row
            if (!visited[0][j] && mat[0][j] == 'O') dfs(mat, 0, j, visited);
            if (!visited[rows - 1][j] && mat[rows - 1][j] == 'O') dfs(mat, rows - 1, j, visited);

        }

        // checking first colulumn and last column
        for (int i = 0; i < rows; i++) {
            if (!visited[i][0] && mat[i][0] == 'O') dfs(mat, i, 0, visited);
            if (!visited[i][cols - 1] && mat[i][cols - 1] == 'O') dfs(mat, i, cols - 1, visited);

        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 'O' && !visited[i][j]) {
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;

    }
};
