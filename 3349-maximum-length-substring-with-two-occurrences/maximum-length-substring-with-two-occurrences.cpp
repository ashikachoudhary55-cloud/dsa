class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0, r = 0;
        int ans = 0;
        int x[26] = {0};

        while (r < s.size()) {
            x[s[r] - 'a']++;

            while (x[s[r] - 'a'] > 2) {
                x[s[l] - 'a']--;
                l++;
            }

            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};