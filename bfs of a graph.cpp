
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int visited[V] = {0};
        visited[0] = 1;
        vector<int> bfs;
        queue<int> q;
        q.push(0);
        while (!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
          // Iterate through all the adjacent nodes of the current node.
            for (auto it: adj[node]){
              // If an adjacent node is not visited yet, mark it as visited and push it into the queue.
                if (!visited[it]){
                    visited[it] = true;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
}; 
// TC: O(N) + O(2E) where N is for inner loop and 2E is for total edges.
