class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int cntFreshOrange = 0;
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        // {{row, col}, time}
        queue<pair<pair<int, int>, int>> q;
        // at first, push all the rotter oranges in queue
        // cause at next 1 sec, these oranges will rot adjacent oranges
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) cntFreshOrange++;
                if (grid[i][j] == 2) {
                    visited[i][j] = 2;
                    q.push({ {i, j}, 0 });
                }
            }
        }
        int time = 0;
        // count the number of fresh oranges that got rotten 
        int count = 0;
        vector<vector<int>> directions = { {-1, 0}, {1, 0},{0, -1}, {0, 1} };
        while (!q.empty()) {
            pair<pair<int, int>, int> current = q.front();
            q.pop();
            int r = current.first.first;
            int c = current.first.second;
            int t = current.second;
            // update time
            time = max(time, t);
            // rot all adjacent oranges
            for (auto& dir : directions) {
                int nextRow = r + dir[0];
                int nextCol = c + dir[1];
                if (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols && grid[nextRow][nextCol] == 1 && visited[nextRow][nextCol] != 2) {
                    q.push({ {nextRow, nextCol}, t + 1 });
                    visited[nextRow][nextCol] = 2;
                    count++;
                }
            }
        }
        if (count == cntFreshOrange) return time;
        return -1;

    }
};
