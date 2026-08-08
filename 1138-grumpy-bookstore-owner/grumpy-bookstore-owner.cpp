class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans = 0;
        for(int i=0; i<grumpy.size(); i++) {
            if (grumpy[i] == 0) {
                ans = ans + customers[i];
            }
        } 
            int l = 0, r = minutes-1, maxi = 0, x = 0;
            while (r < grumpy.size()) {
                for (int i = l; i <= r; i++) {
                    if(grumpy[i] == 1) {
                        x = x + customers[i];
                    }
                }
                maxi = max(maxi, x);
                l ++;
                r ++;
                x = 0;
            }
            ans = ans + maxi;
            return ans;
        
    }
};