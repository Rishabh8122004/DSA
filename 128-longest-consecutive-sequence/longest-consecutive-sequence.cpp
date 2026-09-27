class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for (auto& i : nums)
            st.insert(i);
        int ans = 0;
        for (int x : st) {
            if (st.find(x - 1) == st.end()) {
                int l = 1;
                int y = x + 1;

                while (st.find(y) != st.end()) {
                    l++;
                    y++;
                }

                ans = max(ans, l);
            }
        }
        return ans;
    }
};