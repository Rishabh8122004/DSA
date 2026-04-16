class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& q) {
        int n = nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i = 0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        vector<int>ans(q.size());
        for(int i = 0;i<q.size();i++){
            if(mp[nums[q[i]]].size() == 1)ans[i] = -1;
            else{
                int idx = q[i];
                int pos = -1;
                int lo = 0,hi = mp[nums[q[i]]].size();
                while(lo<=hi){
                    int mid = lo+(hi-lo)/2;
                    if(mp[nums[q[i]]][mid] == idx){
                        pos = mid;break;
                    }
                    else if(mp[nums[q[i]]][mid]>idx) hi = mid-1;
                    else lo = mid+1;
                }
                if(pos == 0){
                    ans[i] = min(abs(mp[nums[q[i]]][pos+1]-idx),abs(n-mp[nums[q[i]]][mp[nums[q[i]]].size()-1]+mp[nums[q[i]]][pos]));
                }
                else if(pos == mp[nums[q[i]]].size()-1){
                    ans[i] = min(abs(n-mp[nums[q[i]]][pos]+ mp[nums[q[i]]][0]),abs(mp[nums[q[i]]][pos-1]-idx));
                }
                else{
                    ans[i] = min(abs(mp[nums[q[i]]][pos-1]-idx),abs(mp[nums[q[i]]][pos+1]-idx));
                }
            }
        }
        return ans;
    }
};