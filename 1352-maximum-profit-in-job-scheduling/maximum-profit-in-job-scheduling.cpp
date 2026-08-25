class Solution {
public:
    int f(int idx, vector<int> &startTime, vector<int> &endTime,
          vector<int> &profit, vector<int> &dp) {
        int n = profit.size();
        if (idx == n) {
            return 0;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        int pick = 0, notPick = 0;
        int low = idx + 1;
        int high = n - 1;
        int next = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (startTime[mid] >= endTime[idx]) {
                next = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        pick = profit[idx] + f(next, startTime, endTime, profit, dp);
        notPick = f(idx + 1, startTime, endTime, profit, dp);
        return dp[idx] = max(pick, notPick);
    }

    int jobScheduling(vector<int>& startTime,
                      vector<int>& endTime,
                      vector<int>& profit) {
        int n = profit.size();
        vector<tuple<int,int,int>> vec;
        for (int i = 0; i < n; i++) {
            vec.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(vec.begin(), vec.end());
        for (int i = 0; i < n; i++) {
            startTime[i] = get<0>(vec[i]);
            endTime[i] = get<1>(vec[i]);
            profit[i] = get<2>(vec[i]);
        }
        vector<int> dp(n, -1);
        return f(0, startTime, endTime, profit, dp);
    }
};