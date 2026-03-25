class Solution {
public:
    void solve(vector<int>& nums,set<vector<int>>& ans,int i){
        //base case
        if(i >= nums.size()) {ans.insert(nums); return;}
        // recursion :
        // swaing current index with all the upcoming index recursively..
        for(int j = i;j<nums.size();j++){
            if(j>i && nums[j] == nums[j-1])continue;
            swap(nums[i],nums[j]);
            solve(nums,ans,i+1);
            //backtracking : making the vector as it was before swap to generate some new permutations
            swap(nums[i],nums[j]);
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        vector<vector<int>>final_ans;
        solve(nums,ans,0); // 0 -> index to begin with

        for(auto x:ans){
            final_ans.push_back(x);
        }
        return final_ans;
    }
};