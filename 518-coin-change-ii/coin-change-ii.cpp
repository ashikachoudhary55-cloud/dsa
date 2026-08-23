class Solution {
public:
    int f(vector<int> &coins, int idx, int amount, vector<vector<int>> &dp) {
        int n = coins.size();
        if (idx >= n) {
            return 0;
        }
        if (amount == 0) {
            return 1;
        }
        if (dp[idx][amount] != -1) {
            return dp[idx][amount];
        }
        int pick = 0, notPick = 0;
        if (amount - coins[idx] >= 0) {
            pick = f(coins, idx, amount - coins[idx], dp);
        }
        notPick = f(coins, idx+1, amount, dp);
        return dp[idx][amount] = pick + notPick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp (n, vector<int> (amount + 1, -1));
        return f(coins, 0, amount, dp);
    }
};