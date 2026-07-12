class Solution {
public:
    int fn(vector<int> &nums, int k, int mid) {
        int n = nums.size();
        int sum = 0, maxi = INT_MIN;
        int count = 1;
        for (int i=0; i<n; i++) {
            sum = sum + nums[i];
            if (sum > mid) {
                count ++;
                if (count > k) return -1;
                sum = nums[i];
            }
            maxi = max(maxi, sum);
        }
        return maxi;
    }
    int f(vector<int> &nums, int k, int low, int high) {
        int x = 0;
        while (low <= high) {
            int mid = low + (high-low)/2;
            int ans = fn(nums, k, mid);
            if (ans != -1) {
                x = ans;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return x;
    }
    int splitArray(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        int n = nums.size(), sum = 0;
        for (int i=0; i<n; i++) {
            sum = sum + nums[i];
            maxi = max(maxi, nums[i]);
        }
        int ans = f(nums, k, maxi, sum);
        return ans;
    }
};