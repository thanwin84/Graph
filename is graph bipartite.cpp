class Solution {
public:
	bool bfs(int current, vector<int> adj[], vector<int>& colored) {
		queue<int> q;
		q.push(current);
		colored[current] = 0;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			for (auto& adjacentNode : adj[node]) {
				// check if the adjacent node is already colored
				if (colored[adjacentNode] != -1) {
					// check if the adjacent node is already colored with same color as parent
					if (colored[adjacentNode] == colored[node]) {
						return false;
					}
				}
				else {
					// mark with opposite color of parent's node
					colored[adjacentNode] = !colored[node];
					q.push(adjacentNode);
				}
			}
		}
		return true;
	}
	bool isBipartite(int V, vector<int>adj[]) {
		vector<int> colored(V, -1);
		for (int i = 0; i < V; i++) {
			if (colored[i] == -1) {
				if (!bfs(i, adj, colored)) {
					return false;
				}
			}
		}
		return true;
	}

};
//tc: O(n) + O(2E) where n is for outer loop and 2E is for total degrees.
