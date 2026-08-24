class Solution {
public:
    int stoneGameVIII(vector<int>& s) {
        int n = s.size();
        for(int i = 1;i<n;i++){
            s[i] += s[i-1];
        }
        int ans = s.back();
        for(int i = n-2;i>0;i--){
            ans = max(ans,s[i]-ans);
        }
        return ans;
    }
};