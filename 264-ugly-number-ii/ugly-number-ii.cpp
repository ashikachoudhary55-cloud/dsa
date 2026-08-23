class Solution {
public:
    int nthUglyNumber(int n) {
        vector <int> arr (n+1);
        int i2 = 1, i3 = 1, i5 = 1;
        arr[1] = 1;
        for (int i = 2; i <= n; i++) {
            int x = arr[i2] * 2;
            int y = arr[i3] * 3;
            int z = arr[i5] * 5;
            int mini = min(min(x, y), z);
            arr[i] = mini;

            if (mini == x) {
                i2 ++;
            }
            if (mini == y) {
                i3 ++;
            }
            if (mini == z) {
                i5 ++;
            }
        }
        return arr[n];
    }
};