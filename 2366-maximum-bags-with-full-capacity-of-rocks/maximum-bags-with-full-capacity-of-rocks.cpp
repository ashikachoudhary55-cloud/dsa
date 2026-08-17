class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector <int> vec(n);
        for (int i = 0; i < n; i++) {
            vec[i] = capacity[i] - rocks[i];
        }
        sort(vec.begin(), vec.end());
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (vec[i] == 0) count ++;
            else {
                if (additionalRocks >= vec[i]) {
                    additionalRocks = additionalRocks - vec[i];
                    count ++;
                } else {
                    break;
                }
            }
        }
        return count;
    }
};