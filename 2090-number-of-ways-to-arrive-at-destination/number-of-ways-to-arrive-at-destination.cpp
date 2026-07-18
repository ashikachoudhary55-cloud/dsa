class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

        vector<long long> dist(n + 1, LLONG_MAX);
        dist[0] = 0;

        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto it : roads) {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<long long> ways(n + 1, 0);
        ways[0] = 1;

        pq.push({0, 0});

        while (!pq.empty()) {
            int node = pq.top().second;
            long long dis = pq.top().first;
            pq.pop();

            if (dis > dist[node]) continue;

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgeWt = it.second;

                if (dis + edgeWt < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWt;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                }
                else if (dis + edgeWt == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};