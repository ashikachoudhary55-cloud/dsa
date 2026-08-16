class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.length();
        int l = 0, r = 0, count = 0, x = 0;
        map<char, int> m;

        while (r < n) {
            m[s[r]]++;
            if (m[s[r]] == k) {
                x++;
            }
            while (x > 0) {
                count = count + (n - r);
                if (m[s[l]] == k) {
                    x--;
                }
                m[s[l]]--;
                l++;
            }

            r++;
        }
        return count;
    }
};