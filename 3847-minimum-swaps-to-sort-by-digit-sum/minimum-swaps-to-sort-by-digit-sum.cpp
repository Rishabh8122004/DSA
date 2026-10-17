class Solution {
public:
    int min_swaps(vector<int>&nums,vector<int>&v){
        unordered_map<int,int>pos;
        for(int i = 0;i<nums.size();i++){
            pos[nums[i]] = i;
        }
        int n = nums.size();
        vector<bool>vis(n,0);
        
        int ans = 0;
        for(int i = 0;i<n;i++){
            if((vis[i] == 1) || (pos[v[i]] == i)){ // this element is either already consideredin a cycle or in a correct place
                continue;
            }
            int j = i;
            int cycle = 0;
            while(vis[j] == 0){
                vis[j] = 1;
                j = pos[v[j]];
                cycle++;
            }
            if(cycle>0)ans += (cycle-1);
        }
        return ans;
    }
    int digit_sum(int x){
        int s = 0;
        while(x){
            s+=(x%10);
            x/=10;
        }
        return s;
    }
    int minSwaps(vector<int>& nums) {
        map<int,vector<int>>mp;
        for(int i = 0;i<nums.size();i++){
            mp[digit_sum(nums[i])].push_back(nums[i]);
        }
        vector<int>v;
        for(auto p:mp){
            auto t = p.second;
            sort(t.begin(),t.end());
            for(auto x:t){
                v.push_back(x);
            }
        }
        return min_swaps(nums,v);
    }
};