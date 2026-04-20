class Solution {
public:
    int maxDistance(vector<int>& c) {
        int n = c.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(c[i]!=c[j])ans = max(ans,abs(i-j));
            }
        }
        return ans;
    }
};