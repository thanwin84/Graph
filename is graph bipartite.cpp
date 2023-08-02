class Solution {
public:
    bool check(vector<vector<int>>& graph, vector<int>& colored, int start) {
        queue<int> q;
        // push the first element in the queue
        q.push(start);
        // color first cell
        colored[start] = 0;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            // explore all neigbour nodes of current node
            for (auto& adjacentNode : graph[current]) {
                // if adjacent node is already colored, check if that color is same as curent node color
                if (colored[adjacentNode] == -1) {
                    colored[adjacentNode] = !colored[current];
                    q.push(adjacentNode);
                }
                else if (colored[adjacentNode] == colored[current]) {
                    // if not colored, color the adjancent node with opposite color of current color
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
                ans = check(graph, colored, i);
            }
            if (ans == false) {
                return false;
            }
        }
        return true;

    }
};
//tc: O(n) + O(2E) where n is for outer loop and 2E is for total degrees.
