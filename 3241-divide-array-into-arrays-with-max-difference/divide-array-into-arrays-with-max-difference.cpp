class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<bool>flag(n,true);
        vector<vector<int>>ans;
        for(int i = 0;i<n;i++){
            if(!flag[i])continue;
            flag[i] = false;
            int a = -1,b = -1;
            for(int j = i+1;j<n;j++){
                if(abs(nums[i]-nums[j])>k)break;
                if(!flag[j])continue;
                if(a == -1 && b == -1){a = nums[j];flag[j] = false;}
                else if(a != -1 && b == -1){b = nums[j];flag[j] = false;}
                if(a != -1 && b != -1)break;
            }
            if(a == -1 || b == -1)return {};
            ans.push_back({nums[i],a,b});

        }
        return ans;
    }
};