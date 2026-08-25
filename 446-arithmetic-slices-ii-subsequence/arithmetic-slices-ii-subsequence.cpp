class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long long, int>> m(n);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long diff = (long long)nums[i] - nums[j];
                auto it = m[j].find(diff);
                int count_at_j = 0;
                if (it == end(m[j])) {
                    count_at_j = 0;
                } else {
                    count_at_j = it->second;
                }

                m[i][diff] = m[i][diff] + count_at_j + 1;

                ans = ans + count_at_j;
            }
        }

        return ans;
    }
};