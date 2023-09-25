class Solution{
    public:
    vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int indegrees[V] = {0};
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
	    return ordering;
	}
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adjList[K];
        for (int ind = 0; ind < N - 1; ind++){
            string s1 = dict[ind];
            string s2 = dict[ind + 1];
            int len = min(s1.size(), s2.size());
            for (int at = 0; at < len; at++){
                if (s1[at] != s2[at]){
                    adjList[s1[at] - 'a'].push_back(s2[at] - 'a');
                    break;
                }
            }
        }
        vector<int> ordering = topoSort(K, adjList);
        string output;
        for (auto it: ordering){
            output = output + char(it + 'a');
        }
        return output;
    }
};
