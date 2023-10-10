class Solution {
public:
    void topoSort(int currentNode, vector<int>& visited, vector<int>& stack, vector<pair<int, int>> adjList[]) {
        visited[currentNode] = 1;
        for (auto &adjacentNode : adjList[currentNode]) {
            int v = adjacentNode.first;
            if (!visited[v]) {
                topoSort(v, visited, stack, adjList);
            }
        }
        stack.push_back(currentNode);
    }

    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        // code here
        vector<pair<int, int>> adjList[N];
        for (int ind = 0; ind < M; ind++) {
            int u = edges[ind][0];
            int v = edges[ind][1];
            int wt = edges[ind][2];
            adjList[u].push_back({ v, wt });
        }
        // fint the toposort
        vector<int> stack;
        vector<int> visited(N, 0);
        for (int ind = 0; ind < N; ind++) {
            if (!visited[ind]) {
                topoSort(ind, visited, stack, adjList);
            }
        }
        vector<int> distance(N, 1e9);
        distance[0] = 0;
        while (!stack.empty()) {
            int node = stack.back();
            stack.pop_back();
            for (auto adjacentNode : adjList[node]) {
                int v = adjacentNode.first;
                int wt = adjacentNode.second;
                if (distance[node] + wt < distance[v]) {
                    distance[v] = distance[node] + wt;
                }
            }

        }
        for (int ind = 0; ind < N; ind++) {
            if (distance[ind] == 1e9) distance[ind] = -1;
        }
        return distance;

    }
};
