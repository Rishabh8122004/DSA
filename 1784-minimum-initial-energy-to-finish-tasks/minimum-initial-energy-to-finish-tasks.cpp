class Solution {
public:
    int minimumEffort(vector<vector<int>>& t) {
        int n = t.size();
        vector<vector<pair<int,int>>>v(10004);
        int mi = INT_MAX,ma = INT_MIN;
        for(int i = 0;i<n;i++){
            v[(t[i][1]-t[i][0])].push_back({t[i][0],t[i][1]});
            mi = min(mi,(t[i][1]-t[i][0]));
            ma = max(ma,(t[i][1]-t[i][0]));
        }
        int ans = 0,rem,sum = 0;
        for(int i = ma;i>=mi;i--){
            if(v[i].empty())continue;
            for(auto p : v[i]){
                if(ans-sum<p.second){
                    ans += p.second-(ans-sum); // p[1] - remainder in ans(if any)
                }
                sum += p.first;
            }
        }
        return ans;
    }
};