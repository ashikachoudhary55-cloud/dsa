class Solution {
public:
    int f(vector<int>& nums, int distinct) {
        int n = nums.size();
        int l = 0, r = 0, count = 0, x = 0;
        map <int, int> m;
        while (r < n) {
            if (m.find(nums[r]) == m.end()) {
                x ++;
            }
            m[nums[r]] ++;
            while (x > distinct) {
                m[nums[l]] --;
                if (m[nums[l]] == 0) {
                    m.erase(nums[l]);
                    x --;
                }
                l ++;
            }
            count = count + (r-l+1);
            r ++;
        }
        return count;
    }
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        int distinct = 0;
        set <int> s;
        for (int i = 0; i < n; i++) {
            s.insert (nums[i]);
        }
        distinct = s.size();
        return f(nums, distinct) - f(nums, distinct-1);
    }
};