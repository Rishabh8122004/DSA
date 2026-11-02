class Solution {
public:
    int minMoves2(vector<int>& nums) {
        float median = 0; ;
        int n = nums.size();
        int nop = 0; // no. of operations
        sort(nums.begin(),nums.end());
        if(n%2==0)
        {
            median = (nums[(n/2)] + nums[(n/2) - 1])/2;
        }
       else{median = nums[n/2]; }
        int idx;// median index;
        float mindiff = INT_MAX;//minimum diffrence b/w median and idx element
        for(int i = 0;i<n;i++)
        {
            if(mindiff > (float)abs(median-nums[i])){mindiff = abs(median-nums[i]); idx = i;}
        }
        for(int i = 0;i<n;i++)
        {
            nop += abs(nums[idx]-nums[i]);
        }
        return nop;
    }
};