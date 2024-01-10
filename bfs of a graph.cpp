
class Solution {
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // we may visit same node twice, so need a visited array
        vector<int> visited(V, 0);
        visited[0] = 1;
        vector<int> bfsOrder;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int currentNode = q.front();
            q.pop();
            bfsOrder.push_back(0);
            // explore all neighbour nodes
            for (auto adjacentNode : adj[currentNode]) {
                // if current adjacent node is not visited, visit it and mark it as visited
                if (!visited[adjacentNode]) {
                    visited[adjacentNode] = 1;
                    q.push(adjacentNode);
                }
            }
        }

        return bfsOrder;
    }
};

// TC: O(N) + O(2E) where N is for inner loop and 2E is for total edges.
