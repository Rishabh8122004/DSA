class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int s = nums[0];
        mp[nums[0]]++;
        int sum = nums[0];
        bool f = true;
        for(int i = 1;i<n;i++){
            cout<<s<<" ";
            mp[nums[i]]++;
            if(f && nums[i] == nums[i-1]+1){
                s+=nums[i];
            }
            else{
                f = false;
                s = nums[0];
            }
            sum = max(sum,s);
        }
        while(1){
            if(mp.count(sum) == 0)return sum;
            sum++;
        }
        return -1;
    }
};