class Solution {
public:
    void dfs(vector<vector<int>>& adjList, int node, vector<int>& visited) {
        visited[node] = 1;
        for (auto it : adjList[node]) {
            if (!visited[it]) {
                dfs(adjList, it, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>> adj) {
        // code here
        int V = adj.size();
        vector<vector<int>> adjList(V);
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adj[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int numOfProvinces = 0;
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++) {
            if (visited[i] == 0) {
                numOfProvinces++;
                dfs(adjList, i, visited);
            }
        }
        return numOfProvinces;

    }
};
// TC: O(N) + 2(V + 2E)
