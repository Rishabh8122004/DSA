class Solution {
public:
    int rev(int x){
        int ans = 0;
        while(x>0){
            ans *= 10;
            ans += (x%10);
            x/=10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>val; //distinct elements
        unordered_map<int,int>mp;
        long ans = 0;
        for(int i = 0;i<n;i++)val[nums[i]]++;
        for(auto p:val){
            int x = p.first;
            int y = p.second;
            x-=rev(x);
            mp[x]+=y;
        }
        for(auto p:mp){
            if(p.second>1)
            ans = (ans+((1LL*(p.second-1)*(p.second))/2))%1000000007; // number of pair
        }
        return ans;
    }
};