class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int s = 0;
        int n = nums.size();
        int ans = INT_MIN;
        for(int i = 0;i<n;i++){
            s+=nums[i];
        }
        for(int i = 0;i<n;i++){
            int x = s-(2*nums[i]);
            int lo = i+1,hi = n-1;
            bool f = false;
            while(lo<=hi){
                int mid = lo+(hi-lo)/2;
                if(nums[mid] == x ) {if(x>ans)ans = x;f = true; break;}
                else if(nums[mid] > x) hi = mid-1;
                else lo = mid+1;
            }
            lo = 0;hi = i-1;
            while(!f && lo<=hi){
                int mid = lo+(hi-lo)/2;
                if(nums[mid] == x ) {if(x>ans) ans = x; break;}
                else if(nums[mid] > x) hi = mid-1;
                else lo = mid+1;
            }
        }
        return ans;
    }
};