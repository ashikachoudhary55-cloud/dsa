class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftSum=0, rightSum=0;
        for (int i=0; i<k; i++) {
            leftSum = leftSum + cardPoints[i];
        }
        int MaxSum = leftSum;
        int rightIdx = n-1;
        for (int i=k-1; i>=0; i--) {
            leftSum = leftSum - cardPoints[i];
            rightSum = rightSum + cardPoints[rightIdx];
            MaxSum = max(MaxSum, leftSum + rightSum);
            rightIdx--;
        }
        return MaxSum;

    }
};