class Solution {
public:
    void bfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int row, int col) {
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if (r-1 >= 0 && grid[r-1][c] == '1' && !vis[r-1][c]) {
    vis[r-1][c] = 1;
    q.push({r-1, c});
}

// Down
if (r+1 < n && grid[r+1][c] == '1' && !vis[r+1][c]) {
    vis[r+1][c] = 1;
    q.push({r+1, c});
}

// Left
if (c-1 >= 0 && grid[r][c-1] == '1' && !vis[r][c-1]) {
    vis[r][c-1] = 1;
    q.push({r, c-1});
}

// Right
if (c+1 < m && grid[r][c+1] == '1' && !vis[r][c+1]) {
    vis[r][c+1] = 1;
    q.push({r, c+1});
}
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> vis (n, vector<int> (m, 0));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    count ++;
                    bfs(grid, vis, i, j);
                }
            }
        }
        return count;
    }
};