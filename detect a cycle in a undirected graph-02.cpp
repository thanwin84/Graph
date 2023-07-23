class Solution {
  public:
    bool detect(int source, int parent, vector<int> adj[], vector<int> &visited){
        visited[source] = 1;
        // explore all its adjacent nodes
        for (auto adjacentNode: adj[source]){
            if (!visited[adjacentNode]){
                if (detect(adjacentNode, source, adj, visited)){
                    return true;
                }
            }
            else {
                if (adjacentNode != parent){
                    return true;
                }
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++){
            if (!visited[i]){
                 if (detect(i, -1, adj, visited)){
                     return true;
                 }
            }
        }
        return false;
    }
};
