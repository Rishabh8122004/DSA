class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>v(n);
        for(int i = 0;i<n;i++){
            v[i] = {nums[i],i};
        }
        sort(v.begin(),v.end());
        int ans = INT_MAX,i = 0;
        while(i+2<n){
            if(v[i].first == v[i+1].first && v[i].first == v[i+2].first){
                ans = min(ans,(abs(v[i].second-v[i+1].second)+abs(v[i].second-v[i+2].second)+abs(v[i+1].second-v[i+2].second)));
            }
            i++;
        }
        return ans == INT_MAX?-1:ans;
    }
};