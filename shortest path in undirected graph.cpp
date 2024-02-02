class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<vector<int>> adjList(N);
        for (auto &it: edges){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        // every index indicates distance from source node
        vector<int> distance(N, 1e9);
        queue<int> q;
        distance[src] = 0;
        q.push(src);
        while (!q.empty()){
            int current = q.front();
            q.pop();
            for (auto &adjacentNode: adjList[current]){
                // distance from current node to adjacentNode
                int currentDistance = distance[current] + 1;
                if (currentDistance < distance[adjacentNode]){
                    distance[adjacentNode]= currentDistance;
                    q.push(adjacentNode);
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
