class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int diff = 0, op = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i-1]) continue;

            diff = nums[i-1] - nums[i] + 1;
            op = op + diff;
            nums[i] = nums[i-1] + 1;
        }
        return op;
    }
};