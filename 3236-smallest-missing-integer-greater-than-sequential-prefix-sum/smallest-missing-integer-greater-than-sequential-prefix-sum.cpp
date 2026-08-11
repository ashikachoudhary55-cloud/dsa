class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0], i;
        for (i=1; i<n; i++) {
            if (nums[i] == nums[i-1] + 1) {
                sum = sum + nums[i];
            } else break;
        }
        vector <int> vec;
        for (int j=0; j<n; j++) {
            if (nums[j] >= sum) {
                vec.push_back (nums[j]); 
            }
        }
        // 12 14 15...sum = 12
        sort (vec.begin(), vec.end());
       
        int ans = sum;

        for (int j = 0; j < vec.size(); j++) {
            if (vec[j] == ans) {
                ans++;
            }
        }

        return ans;
    }
};