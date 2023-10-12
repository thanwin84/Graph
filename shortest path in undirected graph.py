from collections import deque
class Solution:
    def shortestPath(self, edges, n, m, src):
        # code here
        adjList = [[] for _ in range(n)]
        for edge in edges:
            u, v = edge
            adjList[u].append(v)
            adjList[v].append(u)
        visited = [0 for _ in range(n)]
        q = deque()
        distance = [float('inf') for _ in range(n)]
        
        q.append((src, 0))
        visited[src] = 1
        distance[src] = 0
        
        while q:
            currentNode, currentNodeDistance = q.popleft()
            for adjacentNode in adjList[currentNode]:
                if not visited[adjacentNode]:
                    vDistance = currentNodeDistance + 1
                    if vDistance < distance[adjacentNode]:
                        distance[adjacentNode] = vDistance
                        visited[adjacentNode] = 1
                        q.append((adjacentNode, vDistance))
        for index, value in enumerate(distance):
            if value == float('inf'):
                distance[index] = -1
        return distance        
            
