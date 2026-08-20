class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>a,b;
        a.push_back(nums[0]);
        b.push_back(nums[1]);
        for(int i = 2;i<nums.size();i++){
            if(a.back() > b.back()){
                a.push_back(nums[i]);
            }
            else{
                b.push_back(nums[i]);
            }
        }
        for(int i = 0;i<b.size();i++){
            a.push_back(b[i]);
        }
        return a;
    }
};