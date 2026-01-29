class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        n/=2;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n*2;i++){
            int x = nums[i],j = i;
            while(nums[i] == x){
                i++;
                if(i == n*2)break;
            }
            if(i-j == n)return nums[j];
            i--;
        }
        return -1;
    }
};