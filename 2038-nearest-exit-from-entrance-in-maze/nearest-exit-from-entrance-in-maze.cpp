class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int sr = entrance[0], sc = entrance[1];
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        queue<pair<pair<int,int>, int>> q;
        q.push({{sr, sc}, 0});
        vis[sr][sc] = 1;

        int delr [] = {-1,0,1,0};
        int delc [] = {0,1,0,-1};

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();

            for (int i=0; i<4; i++) {
                int nrow = r + delr[i];
                int ncol = c + delc[i];

                if (nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                    maze[nrow][ncol] != '+' && !vis[nrow][ncol]) {

                    if (nrow==0 || nrow==n-1 || ncol==0 || ncol==m-1) {
                        return d + 1;
                    }

                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, d+1});
                }
            }
        }
        return -1;
    }
};