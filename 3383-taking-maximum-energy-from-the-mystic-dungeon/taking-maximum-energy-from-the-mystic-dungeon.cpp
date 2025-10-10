class Solution {
public:
    int maximumEnergy(vector<int>& e, int k) {
        int n = e.size();
        int ans = INT_MIN;
        for(int i = n-1;i>=0;i--){
            if(i-k>=0){
                e[i-k]+=e[i];
            }
            else ans = max(ans,e[i]);
        }
        for(int i = 0;i<n;i++){
            ans = max(ans,e[i]);
        }
        return ans;
    }
};