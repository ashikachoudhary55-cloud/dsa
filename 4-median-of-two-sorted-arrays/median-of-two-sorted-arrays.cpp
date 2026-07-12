class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int i = 0, j = 0, count = -1;
        int x = 0, y = 0;

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                count++;
                if (count == (m + n) / 2 - 1) x = nums1[i];
                if (count == (m + n) / 2) y = nums1[i];
                i++;
            } else {
                count++;
                if (count == (m + n) / 2 - 1) x = nums2[j];
                if (count == (m + n) / 2) y = nums2[j];
                j++;
            }
        }

        while (i < m) {
            count++;
            if (count == (m + n) / 2 - 1) x = nums1[i];
            if (count == (m + n) / 2) y = nums1[i];
            i++;
        }

        while (j < n) {
            count++;
            if (count == (m + n) / 2 - 1) x = nums2[j];
            if (count == (m + n) / 2) y = nums2[j];
            j++;
        }

        if ((m + n) % 2 == 0)
            return (x + y) / 2.0;

        return y;
    }
};