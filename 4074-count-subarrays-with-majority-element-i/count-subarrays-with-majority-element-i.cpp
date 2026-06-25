class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int t) {
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            int cnt = 0;
            for(int j = i;j<nums.size();j++){
                if(nums[j] == t){
                    cnt++;
                }
                else cnt--;
                if(cnt > 0){
                    ans++;
                }
            }
        }
        return ans;
    }
};