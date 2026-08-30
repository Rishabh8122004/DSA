class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
       int n = nums.size();
       int i1 =0,i2=0;
       int mi = nums[0],ma=nums[0];
       for(int i =1;i<n;i++){
           if(nums[i]<mi){
               mi=nums[i];
               i1=i;
           }
           if(nums[i]>ma){
               ma=nums[i];
               i2=i;
           }
       }
       int ans = 0;
       if(i2<i1){
        ans = i2;
        i2 = i1;
        i1 = ans;
        ans = 0;
       }
       ans += min(abs(i1+1),abs(n-i2));
       if(ans == abs(i1+1)){
        ans += min(abs(n-i2),abs(i2-i1));
       }
       else{
        ans += min(abs(i1+1),abs(i2-i1));
       }
      return ans;
    }
};