from collections import deque
class Solution:
    
    #Function to return list containing vertices in Topological order.
    def topoSort(self, V, adj):
        # Code here
        ordering = []
        indegrees = [0 for _ in range(V)]
        for current in range(V):
            for toAdjacentNode in adj[current]:
                indegrees[toAdjacentNode] += 1
        q = deque()
        for ind in range(V):
            if indegrees[ind] == 0:
                q.append(ind)
        
        while q:
            current = q.popleft()
            # current node is without dependency, so push it the stack
            ordering.append(current)
            # decrease indegree value of all its neighbour nodes
            for adjacentNode in adj[current]:
                indegrees[adjacentNode] -= 1
                # if value becomes 0, push it to the queue
                if indegrees[adjacentNode] == 0:
                    q.append(adjacentNode)
        return ordering
        
                
