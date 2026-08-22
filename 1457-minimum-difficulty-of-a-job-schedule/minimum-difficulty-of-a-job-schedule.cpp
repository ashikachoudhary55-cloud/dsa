class Solution {
public:
    int f(vector<int> &jobDifficulty, int d, int idx, vector<vector<int>> &dp) {
        int n = jobDifficulty.size();
        if (dp[idx][d] != -1) {
            return dp[idx][d];
        }
        if (d == 1) {
            int maxD = jobDifficulty[idx];
            for (int i = idx; i < n; i++) {
                maxD = max(maxD, jobDifficulty[i]);
            }
            return dp[idx][d] = maxD;
        }

        int finalResult = INT_MAX;
        int maxD = 0;
        for (int i = idx; i <= n-d; i++) {
            maxD = max(maxD, jobDifficulty[i]);
            int result = maxD + f(jobDifficulty, d-1, i+1, dp);
            finalResult = min(finalResult, result);
        }
        return dp[idx][d] = finalResult;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) return -1;
        vector<vector<int>> dp (n, vector<int> (d+1, -1));
        return f(jobDifficulty, d, 0, dp);
    }
};