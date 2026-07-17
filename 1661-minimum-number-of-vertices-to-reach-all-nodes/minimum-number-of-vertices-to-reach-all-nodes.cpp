class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
        }
        vector<int> indeg(n,0);
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
        vector<int> ans;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            ans.push_back(x);
        }
        return ans;
    }
};