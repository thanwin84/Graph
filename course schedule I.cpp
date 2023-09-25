class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adjList[numCourses];
        for (auto it: prerequisites){
            adjList[it[1]].push_back(it[0]);
        }
        vector<int> indegrees(numCourses, 0);
        for (int ind = 0; ind < numCourses; ind++){
            for(auto toAdjacentNode: adjList[ind]){
                indegrees[toAdjacentNode]++;
            }
        }
        int count = 0;
        queue<int> q;
        for (int ind = 0; ind < numCourses; ind++){
            if (indegrees[ind] == 0){
                q.push(ind);
            }
        }
        while (!q.empty()){
            int current = q.front();
            q.pop();
            count++;
            for (auto adjacentNode: adjList[current]){
                indegrees[adjacentNode]--;
                if (indegrees[adjacentNode] == 0) {
                    q.push(adjacentNode);
                }
            }
        }
        return count == numCourses;

    }
};
