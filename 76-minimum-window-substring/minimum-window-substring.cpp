class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int x = t.size();
        map <char,int> m;
        for (int i = 0; i < x; i++) {
            m[t[i]] ++;
        }
        int l = 0, r = 0;
        int count = 0, sIdx = -1, minLength = INT_MAX;
        while (r < n) {
            if (m[s[r]] > 0) {
                count ++;
            }
            m[s[r]] --;
            while (count == x) {
                if (r-l+1 < minLength) {
                    minLength = r-l+1;
                    sIdx = l;
                }
                m[s[l]] ++;
                if (m[s[l]] > 0) {
                    count --;
                }
                l ++;
            } 
            r ++;
        }
        if (sIdx == -1) return "";
        return s.substr(sIdx, minLength);
    }
};