class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size();
        int length = 0;
        map <int, int> arr;
        for (int i = 0; i<n; i++) {
            arr[i] = 0;
        }
        while (r < n) {
            arr[nums[r]] ++;
            while (arr[nums[r]] > k) {
                    arr[nums[l]] --;
                    l ++;
            }
                length = max(length, r-l+1);
            
            r ++;
        }
        return length;
    }
};