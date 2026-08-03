class Solution {
public:
    int f(int idx, vector<int> &nums, vector<int> &dp) {
        int n = nums.size();
        if(idx >= n) {
            return 0;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        int pick = nums[idx] + f(idx+2, nums, dp);
        int notPick = f(idx+1, nums, dp);
        return dp[idx] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return f(0, nums, dp);
    }
};