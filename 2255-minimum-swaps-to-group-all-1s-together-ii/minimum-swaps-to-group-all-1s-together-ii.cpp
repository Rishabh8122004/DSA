class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int noo = 0; // number of ones
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                noo++;
        }
        if (noo <= 1 || noo >= n - 1) return 0; // only one '1' or no '1'.
        int i = 0, j = 0;
        int ans = n; // a random maximum answer
        int nos = 0; // number of swaps
        while (j < noo) {
            if (nums[j % n] == 0) {
                nos++;
            }
            j++;
        }
        ans = min(ans, nos);
        i = 1;
        while(i<n){
            if(nums[i-1] == 0){nos--;}
            if (nums[j % n] == 0) {
                nos++;
            }
            i++;j++;
            ans = min(ans,nos);
        }
        return ans;
    }
};