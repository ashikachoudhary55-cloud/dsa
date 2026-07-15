class Solution {
public:
    bool bfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int sr, int sc) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        vis[sr][sc] = 1;
        q.push({sr,sc});
        bool closed = true;

        int delr [] = {-1,0,1,0};
        int delc [] = {0,1,0,-1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if (r==0 || c==0 || r==n-1 || c==m-1)
                closed = false;

            for (int i=0; i<4; i++) {
                int nrow = r + delr[i];
                int ncol = c + delc[i];

                if (nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                    !vis[nrow][ncol] && grid[nrow][ncol]==0) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }

        return closed;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int count = 0;

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (!vis[i][j] && grid[i][j] == 0) {
                    if (bfs(grid, vis, i, j))
                        count++;
                }
            }
        }

        return count;
    }
};