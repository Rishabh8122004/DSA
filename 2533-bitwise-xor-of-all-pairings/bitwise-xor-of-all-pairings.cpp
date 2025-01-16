class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        for(int i = 0;i<nums1.size();i++){
            ans^=nums1[i];
        }
        if(nums2.size()%2 == 0 && nums2.size()>0)ans = 0;
        int fans = 0;
        for(int i = 0;i<nums2.size();i++){
            fans^=nums2[i];
        }
        if(nums1.size()%2 == 0 && nums1.size()>0)fans = 0;
        return fans^ans;
    }
};