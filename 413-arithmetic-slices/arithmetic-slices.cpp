class Solution {
public:
    int getsubarray(int x){
        if(x<3)return 0;
        int ans = 0;
        int y = 3;
        while(y<=x){
            ans += (x-y+1);
            y++;
        }
        return ans;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)return 0;
        int len = 2;
        int ans = 0;
        int d = nums[n-1]-nums[n-2];
        for(int i = n-2;i>0;i--){
            if(nums[i]-nums[i-1] != d){
                ans += getsubarray(len);
                len = 2;
                d = nums[i]-nums[i-1]; 
            }
            else len++;
        }
        cout<<getsubarray(len);
        return ans+getsubarray(len);
    }
};