class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& v) {
        int n = v.size(),m = v[0].size();
        for(int j = 0;j<m;j++){
            for(int i = 1;i<n;i++){
                if(v[i][j] == 0)continue;
                v[i][j] += v[i-1][j];
            }
        }
        int ans = 0;
        vector<int>x;
        for(int i = 0;i<n;i++){
            x = v[i];
            sort(x.begin(),x.end());
            for(int j = 0;j<x.size();j++){
                ans = max(ans,(x[j]*(m-j)));
            }
        }
        return ans;
    }
};