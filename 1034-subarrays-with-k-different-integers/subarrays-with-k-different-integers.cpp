class Solution {
public:
    int f(vector<int> &nums, int k) {
        int n = nums.size();
        int l = 0, r = 0, x = 0, count = 0;
        map <int, int> m;
        while (r < n) {
            if (m.find(nums[r]) == m.end()) {
                x ++;
            }
            m[nums[r]] ++;
            while (x > k) {
                m[nums[l]] --;
                if (m[nums[l]] == 0) {
                    m.erase(nums[l]);
                    x--;
                }
                l++;
            }
            count = count + (r-l+1);
            r ++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k-1);
    }
};