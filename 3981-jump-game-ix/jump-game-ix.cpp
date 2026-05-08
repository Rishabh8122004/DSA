class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>mini(n);
        vector<int>maxi = nums;
        int m = nums[n-1],mi = n-1;
        for(int i = n-1;i>=0;i--){
            if(m>nums[i]){
                m = nums[i];
                mi = i;
            }
            mini[i] = {m,mi};
        }
        m = nums[0];
        for(int i = 0;i<n;i++){
            if(m<nums[i]){
                m = nums[i];
            }
            maxi[i] = m;
        }
        vector<int>ans(n);
        for(int i = n-1;i>=0;i--){
            m = maxi[i];
            if(i<n-1){
                if(m > mini[i+1].first){
                    m = ans[i+1];
                }
            }
            ans[i] = m;
        }
        return ans;
    }
};