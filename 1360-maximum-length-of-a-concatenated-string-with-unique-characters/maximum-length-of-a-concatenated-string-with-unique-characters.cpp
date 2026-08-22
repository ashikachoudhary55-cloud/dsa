class Solution {
public:
    bool hasDup (string &s1, string &s2) {
        int arr[26] = {0};
        for (char &ch : s1) {
            if (arr[ch-'a'] > 0) {
                return true;
            }
            arr[ch-'a'] ++;
        }
        for (char &ch : s2) {
            if (arr[ch-'a'] > 0) {
                return true;
            }
        }
        return false;
    }
    int f(vector<string> &arr, int idx, string temp) {
        int n = arr.size();
        if (idx >= n) {
            return temp.length();
        }
        int pick = 0, notPick = 0;
        if (hasDup(arr[idx], temp) == true) {
            notPick = f(arr, idx+1, temp);
        } else {
            notPick = f(arr, idx+1, temp);
            pick = f(arr, idx+1, temp + arr[idx]);
        }
        return max(pick, notPick);
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        string temp = "";
        return f(arr, 0, temp);
    }
};