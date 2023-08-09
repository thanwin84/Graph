class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
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
};

// time: O(V + E)
// space: O(V)
