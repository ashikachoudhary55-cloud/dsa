class Solution {
public:
    int f(vector <int> &coins, int idx, int amount, vector<vector<int>> &dp) {
        int n = coins.size();
        if (idx >= n) {
            return INT_MAX;
        }
        if (amount == 0) {
            return 0;
        }
        if (dp[idx][amount] != -1) {
            return dp[idx][amount];
        }
        //pick ..notPick
        int pick = INT_MAX;
        if (amount - coins[idx] >= 0) {
            int result = f(coins, idx, amount - coins[idx], dp);
            if (result != INT_MAX) {
                pick = 1 + result;
            }
        }
        int notPick = f(coins, idx+1, amount, dp);
        return dp[idx][amount] = min(pick, notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp (coins.size(), vector<int> (amount + 1, -1));
        int ans = f(coins, 0, amount, dp);
        if (ans == INT_MAX) return -1;
        return ans;
    }
};