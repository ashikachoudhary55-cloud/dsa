class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int i = 0, j = n-1, score = 0, maxScore = 0;
        sort (tokens.begin(), tokens.end());
        while (i <= j) {
            //score inc
            if (power >= tokens[i]) {
                score ++;
                power = power - tokens[i];
                i ++;
                maxScore = max(maxScore, score);
            }
            else if (score >= 1) {
                score--;
                power = power + tokens[j];
                j --;
            } else {
                break;
            }
        }
        return maxScore;
    }
};