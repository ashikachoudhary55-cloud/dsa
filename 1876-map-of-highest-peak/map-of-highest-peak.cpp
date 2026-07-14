class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> vis (n, vector<int> (m, 0));
        vector<vector<int>> ht (n, vector<int> (m, 0));
        queue<pair<pair<int,int>, int>> q;
        int height = 0;
        int delr[] = {-1,0,1,0};
        int delc[] = {0,1,0,-1};

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (isWater[i][j] == 1) {
                    vis[i][j] = 1;
                    q.push({{i,j}, height});
                }
            }
        }

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int h = q.front().second;
            ht[r][c] = h;
            q.pop();

            for (int i=0; i<4; i++) {
                int nrow = r + delr[i];
                int ncol = c + delc[i];
                if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]) {
                    q.push({{nrow, ncol}, h + 1});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        return ht;
    }
};