class Solution {
public:
    bool canPartition(string &s, int target, int sum, int idx) {
        if (sum > target) return false;
        if (idx == s.size()) return sum == target;

        int num = 0;
        for (int i = idx; i < s.size(); i++) {
            num = num * 10 + (s[i] - '0'); 
            if (canPartition(s, target, sum + num, i + 1)) return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            string s = to_string(i * i);
            if (canPartition(s, i, 0, 0)) {
                ans += (i * i);
            }
        }
        return ans;
    }
};
