class Solution {
public:
    int f(vector<int> &nums, int k) {
        if (k < 0) return 0;
        int n = nums.size();
        int l = 0, r = 0, x = 0, count = 0;
        while (r < n) {
            if (nums[r] % 2 != 0) {
                x ++;
            }
            while (x > k) {
                if (nums[l] % 2 != 0) {
                    x --;
                }
                l ++;
            }
            count = count + (r-l+1);
            r ++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
       return f(nums, k) - f(nums, k-1);
    }
};