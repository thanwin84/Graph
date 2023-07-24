class Solution
{
public:
	bool isValidCell(vector<vector<int>>& grid, int row, int col) {
		int rows = grid.size();
		int cols = grid[0].size();
		if (row >= 0 && row < rows && col >= 0 && col < cols) {
			return true;
		}
		return false;
	}
	//Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
		// Code here
		int rows = grid.size();
		int cols = grid[0].size();
		vector<vector<int>> visited(rows, vector<int>(cols, 0));
		vector<vector<int>> distanceCell(rows, vector<int>(cols, 0));
		queue<pair<pair<int, int>, int>> q;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (grid[i][j] == 1) {
					q.push({ {i, j}, 0 });
					visited[i][j] = 1;
				}
			    else{
			        visited[i][j] = 0;
			    }
			}
		}
		vector<vector<int>> directions = { {-1, 0}, {1,0}, {0, -1}, {0, 1} };
		while (!q.empty()) {
			pair<pair<int, int>, int> Pair = q.front();
			q.pop();
			int currRow = Pair.first.first;
			int currCol = Pair.first.second;
			int steps = Pair.second;
			distanceCell[currRow][currCol] = steps;
			// explore all four directions
			for (auto &direction : directions) {
				int nextRow = currRow + direction[0];
				int nextCol = currCol + direction[1];
				if (isValidCell(grid, nextRow, nextCol) && !visited[nextRow][nextCol] ) {
					visited[nextRow][nextCol] = 1;
					q.push({ {nextRow, nextCol}, steps + 1 });
				}
			}
		}
		return distanceCell;

	}
};
