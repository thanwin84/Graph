class Solution {
public:
   bool checkDfs(vector<vector<int>>& adj, vector<int> &visited, vector<int> &pathVisited, vector<int>& check, int current) {
        visited[current] = 1;
        pathVisited[current] = 1;
        check[current] = 1;
        // explore all adjacent nodes
        for (auto& adjacentNode : adj[current]) {
            // node is not visited
            if (!visited[adjacentNode]) {
                if (checkDfs(adj, visited, pathVisited, check, adjacentNode)) {
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
        // set it to 0, cause we did not find any cycle 
        check[current] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        const int V = graph.size();
        vector<int> pathVisited(V, 0);
        vector<int> visited(V, 0);
        // if cycle exists mark as 1, otherwise 0
        vector<int> check(V, 0);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                checkDfs(graph, visited, pathVisited, check, i);
            }
        }
        vector<int> safeNodes;
        for (int i = 0; i < V; i++) {
            if (check[i] == 0) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};
// tc: O(V + E)
