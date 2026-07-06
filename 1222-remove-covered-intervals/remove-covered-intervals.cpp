class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& in) {
        int n = in.size();
        sort(in.begin(), in.end(), [](auto& a, auto& b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        int ans = n;
        int max_end = in[0][1];
        for(int i = 1;i<n;i++){
            auto p = in[i];
            if(max_end >= p[1])
                ans --;
            else  max_end = p[1];
        }
        return ans;
    }
};