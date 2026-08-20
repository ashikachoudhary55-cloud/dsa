class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int earn = 0, spent = 0;
        for (int i = 0; i < gas.size(); i++) {
            earn = earn + gas[i];
            spent = spent + cost[i];
        }
        if (spent > earn) return -1;
        int result = 0, total = 0;
        for (int i = 0; i < gas.size(); i++) {
            total = total + gas[i] - cost[i];
            if (total < 0) {
                total = 0;
                result = i+1;
            }
        }
        return result;
    }
};