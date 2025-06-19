class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>ioe(nums[n-1]+1,-1);//index of element
        for(int i = 0;i<n;i++)ioe[nums[i]] = i;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int limit = min(nums[i]+k,nums[n-1]);
            int idx = ioe[limit];
            while(ioe[limit] == -1){
                limit--;
                idx = ioe[limit];
            }
            if(idx>=i)ans++;
            i = idx;
        }
        return ans;
    }
};