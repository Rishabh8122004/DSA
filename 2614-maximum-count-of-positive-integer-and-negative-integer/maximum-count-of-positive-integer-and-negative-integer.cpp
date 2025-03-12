class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int p = -1,n = nums.size();
        int lo = 0,hi = nums.size()-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(nums[mid] == 0){p = mid;hi--;}
            else if(nums[mid]<0){lo++;}
            else hi--;
        }
        p = hi+1;
        lo = 0;hi = nums.size()-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(nums[mid] == 0){n = mid;lo++;}
            else if(nums[mid]<0){lo++;}
            else hi--;
        } 
        n = lo-1;
        return p>nums.size()-n-1?p:(nums.size()-n-1);
    }
};