class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = k-1;
        double sum = 0.0, maxi = 0.0;
        for (int i=l; i<=r; i++) {
            sum = sum + nums[i];
        }
        maxi = sum;
        while (r < n-1) {
            sum = sum - nums[l];
            l ++;
            r ++;
            sum = sum + nums[r];
            maxi = max (maxi, sum);
        }
        double ans = maxi/k;
        return ans; 
    }
};