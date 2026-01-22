class Solution {
public:
    vector<int> solve(vector<int>&nums,int & ans){
        vector<int>temp;
        int a = nums[0]+nums[1];
        int idx = 0;
        for(int i = 1;i<nums.size()-1;i++){
            if(nums[i]+nums[i+1] < a){
                a = nums[i]+nums[i+1];
                idx = i;
            }
        }
        for(int i = 0;i<nums.size();i++){
            if(i == idx){
                temp.push_back(nums[i]+nums[i+1]);
                ans++;
                i++;
            }
            else{
                temp.push_back(nums[i]);
            }
        }
        return temp;
    }
    bool is_sorted(vector<int>&nums){
        for(int i = 1;i<nums.size();i++){
            if(nums[i]<nums[i-1])return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;
        while(!is_sorted(nums)){
            nums = solve(nums,ans);
            for(int i = 0;i<nums.size();i++){
                cout<<nums[i]<<" ";
            }
            cout<<endl;
        }
        return ans;
    }
};