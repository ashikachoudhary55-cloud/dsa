class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n  = plantTime.size();
        vector<pair<int,int>> vec(n);
        for (int i = 0; i < n; i++) {
            vec[i] = {growTime[i], plantTime[i]};
        }
        sort(vec.begin(), vec.end());
        int prevPlant = 0, idx = 0, maxi = 0;
        for (int i = n-1; i >= 0; i--) {
            prevPlant = prevPlant + vec[i].second;
            idx = prevPlant + vec[i].first;
            maxi = max(maxi, idx);
        }
        return maxi;
    }
};