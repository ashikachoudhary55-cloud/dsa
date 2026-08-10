class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //longest subarray containing only 1 zero
        int n = nums.size();
        int l = 0, r = 0, maxLength = 0, count = 0;
        while (r < n) {
            if (nums[r] == 0) {
                count ++;
            }
            while (count > 1) {
                if (nums[l] == 0) {
                    count --;
                }
                l++;
            }
            maxLength = max(maxLength, r-l+1);
            r++;
        }
        return maxLength-1;
    }
};