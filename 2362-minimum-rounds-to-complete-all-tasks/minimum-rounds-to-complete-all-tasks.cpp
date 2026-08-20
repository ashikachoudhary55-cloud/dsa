class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int count = 0;
        map <int, int> m;
        for (int i = 0; i < tasks.size(); i++) {
            m[tasks[i]] ++;
        }
        for (auto it: m) {
            int round = it.second;
            if (round == 1) {
                return -1;
            }
            if (round % 3 == 0) { //3k
                count = count + round/3; 
            } else {
                count = count + (round/3) + 1;
            }
        }
        return count;
    }
};