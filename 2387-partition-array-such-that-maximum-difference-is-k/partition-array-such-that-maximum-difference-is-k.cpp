class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        int m = -1;
        for(int i = 0;i<n;i++)m = max(m,nums[i]);
        vector<int>ioe(m+1,-1);//index of element
        for(int i = 0;i<n;i++)ioe[nums[i]] = i;
        int ans = 0;
        for (int i = 0; i < m+1; i++) {
            if(ioe[i] == -1)continue;
            int limit = min(i+k,m);
            while(ioe[limit] == -1){
                limit--;
            }
            ans++;
            i = limit;
        }
        return ans;
    }
};