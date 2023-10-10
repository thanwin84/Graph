class Solution:
    def dfs(self, current, visited, adj, stack):
        visited[current] = 1
        for adjacentNode in adj[current]:
            if not visited[adjacentNode]:
                self.dfs(adjacentNode, visited, adj, stack)
                
        # by recursively,  we have already inserted nodes into stack that comes after current node
        # which ensures that U comes before V if U is directed to V
        # Now insert the current node into the stack
        stack.append(current)
        
        
    #Function to return list containing vertices in Topological order.
    def topoSort(self, V, adj):
        # Code here
        visited = [0 for _ in range(V)]
        stack = []
        for i in range(V):
            if  not visited[i]:
                self.dfs(i, visited, adj, stack);
     
                
        return stack[::-1]

# TC: O(V) + O(E) Space: O(V)
