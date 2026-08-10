class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, sum = 0, maxSum = 0;
        map <int, int> m;
        while (r < n) {
            if(m.find(nums[r]) == m.end()) { //element is not present
                m[nums[r]] = r;
                sum = sum + nums[r];
                maxSum = max(maxSum, sum);
            } else {
                while (l <= m[nums[r]]) {
                    sum = sum - nums[l];
                    l++;
                }
                
                m[nums[r]] = r; 
                sum = sum + nums[r];
                maxSum = max(maxSum, sum);
            }
            r ++;
        }
        return maxSum;
    }
};