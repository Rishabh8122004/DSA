class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int minsum = INT_MAX;
        for(int k = l;k<=r;k++){
            int sum = 0;
            for(int i = 0;i<k;i++){sum+=nums[i];}
            if(sum>0 && sum<minsum) minsum = sum;
            int i = 1,j = k;
            while(j<n){
                sum+=(nums[j]-nums[i-1]);
                if(sum>0 && sum<minsum) minsum = sum;
                i++;j++;
            }
        }
        return minsum == INT_MAX? -1:minsum;
    }
};