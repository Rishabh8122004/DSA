class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 2)
            return 2;
        int e = 0, o = 0; // no. of even,odd elements
        int len = 1;      // including first element
        bool last = (nums[0] % 2 == 0 ? true:false); // false means odd, true means even
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                e++;
                if (!last) {
                    len++;
                    last = true;
                }
            } else {
                o++;
                if (last) {
                    len++;
                    last = false;
                }
            }
        }
        int ans = max(o, e);
        return max(len, ans);
    }
};