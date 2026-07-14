class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis (n, vector<int> (n, 0));
        queue<pair<pair<int,int>, int>> q;
        int dist = 0;
        int land = 0;
        int delr [] = {-1,0,1,0};
        int delc [] = {0,1,0,-1};

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1) {
                    land ++;
                    q.push({{i,j}, dist});
                    vis[i][j] = 1;
                } 
            }
        }

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            dist = max(d, dist);
            q.pop();

            for (int i=0; i<4; i++) {
                int nrow = r + delr[i];
                int ncol = c + delc[i];
                if (nrow>=0 && nrow<n && ncol>=0 && ncol<n && !vis[nrow][ncol]) {
                    q.push({{nrow, ncol}, d + 1});
                    vis[nrow][ncol] = 1;
                }
            }
        }

        if (land == 0 || land == n*n) return -1;

        return dist;

    }
};