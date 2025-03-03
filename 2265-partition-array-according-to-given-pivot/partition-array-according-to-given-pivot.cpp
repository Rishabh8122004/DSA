class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>v;
        int c = 0,d = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]<pivot){v.push_back(nums[i]);}
            else if(nums[i] == pivot)c++;
            else {swap(nums[d],nums[i]);d++;}
        }
        d = 0;int k = v.size();
        for(int i = v.size();i<n;i++){
            if(i-k<c)v.push_back(pivot);
            else {v.push_back(nums[d]);d++;}
        }
        return v;
    }
};