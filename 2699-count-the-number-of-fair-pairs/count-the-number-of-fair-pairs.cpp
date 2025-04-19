class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long long int pairs = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n;i++){
            int x = lower-nums[i];
            int y = upper-nums[i];
            int lidx = -1,uidx = -1;
            int lo = i+1,hi = n-1;
            while(lo<=hi){
                int mid = (lo+hi)/2;
                if(nums[mid] < x) lo = mid+1;
                else hi = mid-1;
            }
            lidx = lo;
            lo = i+1;hi = n-1;
            while(lo<=hi){
                int mid = (lo+hi)/2;
                if(nums[mid] <= y) lo = mid+1;
                else hi = mid-1;
            }
            uidx = hi;
            if(uidx<lidx) continue;
            pairs+=(uidx-lidx+1);
        }
        return pairs;
    }
};