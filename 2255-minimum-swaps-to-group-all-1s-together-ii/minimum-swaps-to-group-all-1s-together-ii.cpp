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
        int len = 0; // number of ones in current window
        int nos = 0; // number of swaps
        while (len < noo) {
            if (nums[j % n] == 0) {
                if (noo - len > 0)
                    nos++;
            }
            len++;
            j++;
        }
        ans = min(ans, nos);
        cout<<ans<<" ";
        i = 1;
        while(i<n){
            if(nums[i-1] == 0){nos--;}
            if (nums[j % n] == 0) {
                nos++;
            }
            i++;j++;
            ans = min(ans,nos);
            cout<<ans<<" ";
        }
        return ans;
    }
};