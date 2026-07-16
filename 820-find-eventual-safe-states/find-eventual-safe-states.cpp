class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        for (int i=0; i<n; i++) {
            for (auto it: graph[i]) {
                adj[it].push_back(i);
            }
        }
        vector<int> indeg(n, 0);
        for (int i=0; i<n; i++) {
            for (auto it: adj[i]) {
                indeg[it] ++;
            }
        }
        queue<int> q;
        for (int i=0; i<n; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            topo.push_back(node);
            q.pop();

            for (auto it: adj[node]) {
                indeg[it]--;
                if (indeg[it] == 0) {
                    q.push(it);
                }
            }
        }
        sort(topo.begin(), topo.end());
        return topo;
    }
};