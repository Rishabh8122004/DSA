class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int lo = nums2.size()-1,hi = 0;
        int ans = 0;
        int n = min(nums1.size(),nums2.size());
        for(int i = 0;i<n;i++){
            if(nums1[i]>nums2[i])continue;
            hi = i;
            lo = nums2.size()-1;
            while(lo>=hi){ // binary search for a non-increasing array
                int mid = hi+(lo-hi)/2;
                if(nums2[mid] >= nums1[i]){
                    ans = max(ans,abs(mid-i));
                    hi = mid+1;
                }
                else lo = mid-1;
            }
        }
        return ans;
    }
};