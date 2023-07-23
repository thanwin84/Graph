class Solution {
  public:
    bool detect(int source, vector<int> adj[], vector<int> &visited){
        // pair<currNode, parent>
        queue<pair<int,int>> q;
        q.push({source, -1});
        visited[source] = 1;
        while (!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            // first we will check all its adjacent node
            for (auto adjacentNode:adj[node]){
                // we have two case here
                //case 1: if visited, we have to check if it is the parent node
                // if it's not the parent node and visited, that means someone already
                // has visited this node. So we can say there is cycle
                if (visited[adjacentNode]){
                    if (parent != adjacentNode){
                        return true;
                    }
                }
                
                // case 2: if not visited, just push it to the q
                else {
                    visited[adjacentNode] = 1;
                    q.push({adjacentNode, node});
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
                 if (detect(i, adj, visited)){
                     return true;
                 }
            }
        }
        return false;
    }
};
// TC: O(N + 2E)
// SP: O(N)
