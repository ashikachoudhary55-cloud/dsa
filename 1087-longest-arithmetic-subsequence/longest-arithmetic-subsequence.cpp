class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long long, int>> m(n);
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int difference = nums[i] - nums[j];
                auto it = m[j].find(difference);
                int length_at_j = 0;
                if (it == m[j].end()) {
                        length_at_j = 0;
                } else {
                        length_at_j = it->second;
                }
                int length = 0;
                if (length_at_j == 0) {
                        length = 2;
                } else {
                        length = length_at_j + 1;
                }
                m[i][difference] = max(m[i][difference], length);
                ans = max(ans, m[i][difference]);
            }
        }
        return ans;
    }
};