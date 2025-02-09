class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            bool flag = false;
            int a = sqrt(nums[i][i]); 
            for(int j = 2;j<=a;j++){
                if(nums[i][i]%j == 0){flag = true;break;}
            }
            if(!flag) ans = max(ans,nums[i][i]);
            flag = false;
            a = sqrt(nums[i][n-1-i]); 
            for(int j = 2;j<=a;j++){
                if(nums[i][n-1-i]%j == 0){flag = true;break;}
            } 
            if(!flag)ans = max(ans,nums[i][n-1-i]);  
        }
        if(ans == 1)return 0;
        return ans;
    }
};