class Solution {
    void dfs(int node, vector<int> adj[], int visited[], vector<int> &ls){
        visited[node] = 1;
        ls.push_back(node);
        for (auto it: adj[node]){
            if (!visited[it]){
                dfs(it, adj, visited, ls);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int visited[V] = {0};
        vector<int> ls;
        int start = 0;
        dfs(start, adj, visited, ls);
        return ls;
    }
};

// space: O(V) and TC: O(V) + O(2E)
