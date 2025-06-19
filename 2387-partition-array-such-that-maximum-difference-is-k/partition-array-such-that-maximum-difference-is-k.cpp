class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        int m = -1;
        for(int i = 0;i<n;i++)m = max(m,nums[i]);
        vector<int>ioe(m+1,-1);//index of element of the size = max element in nums
        for(int i = 0;i<n;i++)ioe[nums[i]] = i; // last index a num appeared , doesn't matter coz all the numbers(index) are already in sorted manner
        int ans = 0;
        for (int i = 0; i < m+1; i++) {
            if(ioe[i] == -1)continue;
            ans++; // though we reached our limit means we can't take any more in this range
            i = min(i+k,m); // gotta take 'i' to the next range
        }
        return ans;
    }
};