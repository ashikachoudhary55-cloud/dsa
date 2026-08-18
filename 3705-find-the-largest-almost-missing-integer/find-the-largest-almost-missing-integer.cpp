class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        map <int, int> m;
        for (int i = 0; i <= n - k; i++) {
            set<int> s;
            for (int j = i; j < i + k; j++) {
                s.insert(nums[j]);
            }
            for (auto x : s) {
                m[x]++;
            }
        }

        int ans = -1;
        for (auto x : m) {
            if (x.second == 1) {
                ans = max(ans, x.first);
            }
        }

        return ans;
    }
};