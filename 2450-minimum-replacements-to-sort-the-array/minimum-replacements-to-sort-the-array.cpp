class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long parts = 0, op = 0;
        for (int i = n-2; i >= 0; i--) {
            if (nums[i] <= nums[i+1]) continue;

            parts = nums[i] / nums[i+1];
            if (nums[i] % nums[i+1] != 0) parts ++;
            op = op + (parts-1);
            nums[i] = nums[i] / parts;
        }
        return op;
    }
};