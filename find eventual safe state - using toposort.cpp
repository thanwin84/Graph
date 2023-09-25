class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // invert the indegree to outdegree
        int V = graph.size();
        vector<int> adj[V];
        for (int ind = 0; ind < V; ind++){
            for (auto adjacentNode: graph[ind]){
                adj[adjacentNode].push_back(ind);
            }
        }
        vector<int> indegrees(V, 0);
	    for (int ind = 0; ind < V; ind++){
	        for (auto to: adj[ind]){
	            indegrees[to]++;
	        }
	    }
	    // store nodes that don't have any dependency
	    queue<int> q;
	    for (int ind = 0; ind < V; ind++){
	        if (indegrees[ind] == 0){
	            q.push(ind);
	        }
	    }
	    vector<int> ordering;
	    while (!q.empty()){
	        int currentNode = q.front();
	        q.pop();
	        // node without dependencies
	        ordering.push_back(currentNode);
	        // decrease indegrees value of all adjacent nodes
	        for (auto adjacentNode: adj[currentNode]){
	            indegrees[adjacentNode]--;
	            if (indegrees[adjacentNode] == 0) q.push(adjacentNode);
	        }
	    }
        sort(ordering.begin(), ordering.end());
        return ordering;
    }
};
