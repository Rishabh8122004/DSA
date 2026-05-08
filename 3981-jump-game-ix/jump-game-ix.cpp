class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int>mini(n);
        vector<int>maxi(n);
        int m = nums[n-1];
        for(int i = n-1;i>=0;i--){
            if(m>nums[i]){
                m = nums[i];
            }
            mini[i] = m;
        }
        m = nums[0];
        for(int i = 0;i<n;i++){
            if(m<nums[i]){
                m = nums[i];
            }
            maxi[i] = m;
        }
        for(int i = n-1;i>=0;i--){
            m = maxi[i];
            if(i<n-1){
                if(m > mini[i+1]){
                    m = nums[i+1];
                }
            }
            nums[i] = m;
        }
        return nums;
    }
};