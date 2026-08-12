class Solution {
public:
    int f(vector<int> &nums, int goal) { //sum <= goal
        if (goal < 0) return 0;
        int l = 0, r = 0, n = nums.size();
        long long sum = 0;
        int count = 0;
        while (r < n) {
            sum = sum + nums[r];
            while (sum > goal) {
                sum = sum - nums[l];
                l++;
            }
            count = count + (r-l+1);
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return f(nums, goal) - f(nums, goal-1);
    }
};