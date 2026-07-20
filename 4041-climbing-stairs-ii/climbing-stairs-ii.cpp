class Solution {
public:
    long long calculate(int i, int j, vector<int> &costs) {
        return 1LL * costs[j - 1] + 1LL * (j - i) * (j - i);
    }

    long long f(int n, vector<int>& costs, int idx, vector<long long> &dp) {
        if (idx == n) return 0;
        if (dp[idx] != -1) return dp[idx];

        long long ans = LLONG_MAX;

        if (idx + 1 <= n)
            ans = min(ans, f(n, costs, idx + 1, dp) + calculate(idx, idx + 1, costs));

        if (idx + 2 <= n)
            ans = min(ans, f(n, costs, idx + 2, dp) + calculate(idx, idx + 2, costs));

        if (idx + 3 <= n)
            ans = min(ans, f(n, costs, idx + 3, dp) + calculate(idx, idx + 3, costs));

        return dp[idx] = ans;
    }

    long long climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n + 1, -1);
        return f(n, costs, 0, dp);
    }
};