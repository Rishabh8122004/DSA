class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        bool sorted = true;
        for(int i = 0;i+1<n;i++){
            if(nums[i+1]<nums[i])sorted = false;
        }
        if(sorted)ans = 1;
        int k = 2;
        while (k <= n) {
            if((n%k) != 0){k++;continue;}
            int i = 0, j = k - 1;
            bool f = true;
            int ma = 0,mi; // maximum element in previous subarray  
            while (j < n) {
                bool dec = false; // is the subarray have a decreasing order ?
                int temp = nums[i];
                if(ma > nums[i]){f = false;break;}
                while (i < j) {
                    if (nums[i + 1] < nums[i]) {
                        if (dec) { // there is already a decreasing pattern
                                   // appeared , means we cannot sort by
                                   // rotation
                            f = false;
                            break;
                        }
                        dec = true;
                    }
                    i++;
                    temp = max(temp,nums[i]);
                    if((i == j )&& dec){
                        if(nums[i-k+1] < nums[i])f = false; // decreasing pattern occured more than once
                    }
                    if(ma > nums[i]){f = false;break;}
                }
                if (!f)
                    break;
                i = j + 1;
                j += k;
                ma = temp;
            }
            if(f){ans+=k;cout<<k<<"  ";}
            k++;
        }
        return ans;
    }
};