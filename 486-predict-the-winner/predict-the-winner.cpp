class Solution {
public:
    bool solve(vector<int>&nums,int i,int j,long long p1,long long p2,bool f){
        if(i>j)return p1>=p2;
        if(f){ // player 1 is trying it's best 
            if(solve(nums,i+1,j,p1+nums[i],p2,false))return true;
            return solve(nums,i,j-1,p1+nums[j],p2,false);
        }
        if(!solve(nums,i+1,j,p1,p2+nums[i],true))return false; // player 2 is trying its best
        return solve(nums,i,j-1,p1,p2+nums[j],true);
    }
    bool predictTheWinner(vector<int>& nums) {
        long long p1=0,p2=0;
        return solve(nums,0,nums.size()-1,p1,p2,true);
    }
};