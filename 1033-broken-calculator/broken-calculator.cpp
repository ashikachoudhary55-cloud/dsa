class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int count = 0;
        while (startValue != target) {
            if (target % 2 != 0) { //odd
                target = target + 1;
                count ++;
            } else if (target > startValue && target % 2 == 0) {
                target = target / 2;
                count ++;
            } else if (target < startValue && target % 2 == 0) {
                target = target + 1;
                count ++;
            }
        }
        return count;
    }
};