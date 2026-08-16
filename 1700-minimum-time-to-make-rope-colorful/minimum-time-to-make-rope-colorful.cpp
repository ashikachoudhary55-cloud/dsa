class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int x = 1, time = 0;
        int prev = neededTime[0];

        while (x < n) {
            int curr = neededTime[x];

            if (colors[x] == colors[x - 1]) {
                time = time + min(prev, curr);
                prev = max(prev, curr);
            }
            else {
                prev = curr;
            }

            x++;
        }

        return time;
    }
};