class Solution {
public:
    void dfs(int current, vector<vector<pair<int, int>>>& adjList, vector<int>& visited, vector<int>& nodes) {
        visited[current] = 1;
        for (auto& it : adjList[current]) {
            int adjacentNode = it.first;
            if (!visited[adjacentNode]) {
                dfs(adjacentNode, adjList, visited, nodes);
            }
        }
        nodes.push_back(current);
    }
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adjList(N);
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adjList[u].push_back({v, wt});
        }
        vector<int> topoSort;
        vector<int> visited(N, 0);
        
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                dfs(i, adjList, visited, topoSort);
            }
        }
        vector<int> distance(N, 1e9);
        distance[topSort.back() - 1] = 0;
        while (topoSort.size() > 0) {
            int current = topoSort.back();
            topoSort.pop_back();
            // explore all neighbour nodes
            for (auto& adjacentNode : adjList[current]) {
                
                int v = adjacentNode.first;
                int wt = adjacentNode.second;
                if (distance[current] + wt < distance[v]){
                    
                    distance[v] = distance[current] + wt;
                }
            }
        }
        for (int i =0; i < N; i++){
            if (distance[i] == 1e9){
                distance[i] = -1;
            }
        }
        return distance;
            
    }
};
// time: O( V + E)
