class Solution {
public:
    int bfs (vector<vector<int>> &grid, vector<vector<int>> &vis, int sr, int sc) {
        queue<pair<int,int>> q;
        q.push({sr, sc});
        vis[sr][sc] = 1;

        int delr [] = {-1, 0, 1, 0};
        int delc [] = {0,1,0,-1};

        bool x = true;
        int count = 0;

        int n = grid.size();
        int m = grid[0].size();

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            count++;

            if (r == 0 || r == n-1 || c == 0 || c == m-1)
                x = false;

            for (int i=0; i<4; i++) {
                int nrow = r + delr[i];
                int ncol = c + delc[i];

                if (nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                    !vis[nrow][ncol] && grid[nrow][ncol] == 1) {

                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }

        if (x)
            return count;
        return 0;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis (n, vector<int> (m, 0));

        int ans = 0;

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    ans += bfs(grid, vis, i, j);
                }
            }
        }

        return ans;
    }
};