class Solution:
    def topoSort(self, currentNode, visited, adjList, stack):
        visited[currentNode] = 1
        for adjacentNode in adjList[currentNode]:
            v, _ = adjacentNode
            if not visited[v]:
                self.topoSort(v, visited, adjList, stack)
        stack.append(currentNode)
        
    def shortestPath(self, n : int, m : int, edges : List[List[int]]) -> List[int]:
        adjList = [[] for _ in range(n)]
        for current in edges:
            u, v, wt = current
            adjList[u].append((v, wt))
        stack = []
        visited = [0 for _ in range(n)]
        for ind in range(n):
            if not visited[ind]:
                self.topoSort(ind, visited, adjList, stack)
            
        distance = [float('inf') for _ in range(n)]
        distance[0] = 0
        while stack:
            currentNode = stack.pop()
            for adjacentNode in adjList[currentNode]:
                v, wt = adjacentNode
                if distance[currentNode] + wt < distance[v]:
                    distance[v] = distance[currentNode] + wt
        for index, value in enumerate(distance):
            if value == float('inf'):
                distance[index] = -1
        return distance
            
