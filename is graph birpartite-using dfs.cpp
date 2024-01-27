class Solution {
public:
	bool dfs(int current, vector<int> adj[], vector<int>& colored, int color) {
		colored[current] = color;
		for (auto& adjacentNode : adj[current]) {
			if (colored[adjacentNode] == -1) {
				if (!dfs(adjacentNode, adj, colored, !color)) {
					return false;
				}
			}
			else {
				if (colored[adjacentNode] == colored[current]) {
					return false;
				}
			}
		}
		return true;
	}
	bool isBipartite(int V, vector<int>adj[]) {
		vector<int> colored(V, -1);
		for (int i = 0; i < V; i++) {
			if (colored[i] == -1) {
				if (!dfs(i, adj, colored, 1)) {
					return false;
				}
			}
		}
		return true;
	}

};
