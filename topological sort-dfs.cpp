// topological sort is only possible in DAG
class Solution
{
	public:
	void dfs(int current, vector<int> adj[], vector<int> &visited, vector<int> &stack){
	    visited[current] = 1;
	    for (auto &adjacentNode: adj[current]){
	        if (!visited[adjacentNode]){
	            dfs(adjacentNode, adj, visited, stack);
	        }
	    }
	    stack.push_back(current);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> visited(V, 0);
	    vector<int> stack;
	    
	    for (int at = 0; at < V; at++){
	        if (!visited[at]){
	            dfs(at, adj, visited, stack);
	        }
	    }
	    reverse(stack.begin(),stack.end());
	    return stack;
	}
};

// TC: O(V + E)
