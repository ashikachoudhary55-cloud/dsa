class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, sum = 0, minLength = INT_MAX;
        while (r < n) {
            sum = sum + nums[r];
            while (sum >= target) {
                minLength = min(minLength, r-l+1);
                sum = sum - nums[l];
                l++;
            }
            r++;
        }
        if (minLength == INT_MAX) return 0;
        return minLength;
    }
};