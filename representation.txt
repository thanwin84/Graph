*undirected graph*
**representation of graph in matrix**
int main() {
	int n,m;
	cin >> n >> m;
  // graph here
	vector<vector<int>> matrix(n + 1, vector<int>(m + 1));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		matrix[a][b] = 1;
		matrix[b][a] = 1;
	}
	return 0;
}
**representation of graph in list**
int main() {
    int n = 0;
    int m = 0;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (auto o : adj) {
        for (auto i : o) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
