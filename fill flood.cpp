class Solution {
public:
    bool isValidBoundary(vector<vector<int>>& image, int row, int col) {
        int rows = image.size();
        int cols = image[0].size();
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            return true;
        }
        return false;
    }
    void bfs(vector<vector<int>>& image, int sr, int sc, int color, vector<vector<int>>& copyOfImage) {
        int initialColor = image[sr][sc];
        // set current cell color to new color
        copyOfImage[sr][sc] = color;
        queue<pair<int, int>> q;
        q.push({ sr, sc });
        vector<vector<int>> directions = { {-1, 0}, {1, 0},{0, -1}, {0, 1} };
        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();
            for (auto & direction : directions) {
                int nextRow = current.first + direction[0];
                int nextCol = current.second + direction[1];
                // checking if next cell can be colored or not
                if (isValidBoundary(image, nextRow, nextCol) && image[nextRow][nextCol] == initialColor && copyOfImage[nextRow][nextCol] != color) {
                    q.push({ nextRow, nextCol });
                    // set color
                    copyOfImage[nextRow][nextCol] = color;
                }
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size();
        int cols = image[0].size();
        vector<vector<int>> copyOfImage = image;
        bfs(image, sr, sc, color, copyOfImage);
        return copyOfImage;
    }
};
