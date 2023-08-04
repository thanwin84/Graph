// If we solved the way solved to detect cycle in an undirected graph, it will not
class Solution{
  public:
      // Function to detect cycle in a directed graph.
      bool check(vector<int> adj[], int visited[], int pathVisited[], int current) {
          visited[current] = 1;
          pathVisited[current] = 1;
          // explore all adjacent nodes
          for (auto& adjacentNode : adj[current]) {
              // node is not visited
              if (!visited[adjacentNode]) {
                  if (check(adj, visited, pathVisited, adjacentNode)) {
                      return true;
                  }
              }
              // node is visited
              else {
                  // check if the visited node is on the same path
                  if (pathVisited[adjacentNode]) {
                      return true;
                  }
              }
              
          }
          // remove the path, cause we did not find cycle in this path
          pathVisited[current] = 0;
          return false;
      }
   
      bool isCyclic(int V, vector<int> adj[]) {
          // code here
          // keep track of visited node
          int visited[V] = { 0 };
          // keep track of nodes that are on the same path
          int pathVisited[V] = { 0 };
          for (int i = 0; i < V; i++) {
              if (!visited[i]) {
                  if (check(adj, visited, pathVisited, i)){
                      return true;
                  }
              }
              
          }
          return false;
      }
};
// tc: O(V + E)
