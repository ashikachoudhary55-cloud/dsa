class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        map<string, int> m;
        for (int i = 0; i < n; i++) {
            m[words[i]]++;
        }

        bool centre = false;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            string x = words[i];
            string rev = x;
            reverse(rev.begin(), rev.end());

            if (x != rev) { // ab....ba
                if (m[x] > 0 && m[rev] > 0) {
                    ans = ans + 4;
                    m[x]--;
                    m[rev]--;
                }
            }
            else { // aa....aa
                if (m[x] >= 2) {
                    m[x] = m[x] - 2;
                    ans = ans + 4;
                }
                else if (m[x] == 1 && centre == false) {
                    centre = true;
                    m[x]--;
                    ans = ans + 2;
                }
            }
        }

        return ans;
    }
};