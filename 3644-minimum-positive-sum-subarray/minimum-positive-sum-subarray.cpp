class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int minSum = INT_MAX, left = 0, right = 0;

        while (left < n) {
            right = left;
            int sum = 0;

            while (right < n) {
                sum = sum + nums[right];
                int length = right - left + 1;
                if (length >= l && length <= r) {
                    if (sum > 0) {
                        minSum = min(minSum, sum);
                    }
                }
                if (length > r) {
                    break;
                }
                right++;
            }
            left++;
        }

        if (minSum == INT_MAX) {
            return -1;
        }

        return minSum;
    }
};