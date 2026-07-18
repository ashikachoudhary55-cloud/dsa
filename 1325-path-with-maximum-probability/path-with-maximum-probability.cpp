class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<pair<double,int>, vector<pair<double,int>>> pq;
        vector<double> dist(n, 0.0);
        dist[start_node] = 1.0;
        pq.push({1.0, start_node});

        while (!pq.empty()) {
            int node = pq.top().second;
            double dis = pq.top().first;
            pq.pop();

            for (auto it: adj[node]) {
                int adjNode = it.first;
                double edgeWt = it.second;
                if (dis*edgeWt > dist[adjNode]) {
                    dist[adjNode] = dis*edgeWt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist[end_node];
    }
};