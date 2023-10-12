class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
        vector<int> adjList[N];
        for (int ind = 0; ind < M; ind++) {
            int u = edges[ind][0];
            int v = edges[ind][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<int> visited(N, 0);
        // first: node, second: distance
        queue<pair<int, int>> q;
      // distance[i] indicates the distance from source
        vector<int> distance(N, 1e9);
        // src node distance is always 0
        q.push({ src, 0 });
        visited[src] = 1;
        distance[src] = 0;
      
        while (!q.empty()) {
            pair<int, int> Pair = q.front();
            int currentNode = Pair.first;
            int currentNodeDis = Pair.second;

            q.pop();
            // explore all neigbour nodes 
            for (auto & adjacentNode : adjList[currentNode]) {
                if (!visited[adjacentNode]) {
                    // if the distance from u to v is less than precalculated distance of
                    // v, then update the distance
                    int distanceUToV = currentNodeDis + 1;
                    if (distanceUToV < distance[adjacentNode]) {
                        distance[adjacentNode] = distanceUToV;
                        q.push({ adjacentNode, distanceUToV });
                        visited[adjacentNode] = 1;
                    }
                }
            }
        }
        // distance[ind] = INT_MAX means it is unreachable
        for (int ind = 0; ind < N; ind++) {
            if (distance[ind] == 1e9) {
                distance[ind] = -1;
            }
        }
        return distance;
    }
};
