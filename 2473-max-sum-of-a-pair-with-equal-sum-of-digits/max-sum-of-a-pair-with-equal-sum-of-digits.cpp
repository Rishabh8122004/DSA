class Solution {
public:
    int findsum(int n){
        int sum = 0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> sum;
        for(int i = 0;i<n;i++){
            sum.push_back({findsum(nums[i]),i});
        }
        sort(sum.begin(),sum.end());
        int maxsum = -1;
        for(int i = 0;i<n-1;i++){
            int m = nums[sum[i][1]];
            while(i<n-1 && sum[i][0] == sum[i+1][0]){
                m = max(m,nums[sum[i][1]]);
                maxsum = max(maxsum,m+nums[sum[i+1][1]]);
                i++;
            }
        }
        return maxsum;
    }
};