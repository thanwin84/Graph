class Solution {
public:
    bool check(vector<vector<int>>& graph, vector<int>& colored, int current, bool color) {
        colored[current] = color;
        // explore all the adjacent nodes
        for (auto &adjacentNode: graph[current]){
            // if adjacent node is not colored, color it 
            if (colored[adjacentNode] == -1){
                if (check(graph, colored, adjacentNode, !color) == false){
                    return false;
                }
            }
            else {
                if (colored[adjacentNode] == colored[current]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colored(n, -1);
        bool ans = true;
        for (int i = 0; i < n; i++) {
            if (colored[i] == -1) {
                ans = check(graph, colored, i, true);
            }
            if (ans == false) {
                return false;
            }
        }
        return true;

    }
};
