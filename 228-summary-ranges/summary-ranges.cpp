class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        for(int i = 0;i<nums.size();i++){
            int a = nums[i];
            int b = a;
            int j = i;
            while(j+1<nums.size() && nums[j+1] == b+1){
                b++;
                j++;
            }
            if(a == b){
                ans.push_back(to_string(a));
            }else{
                ans.push_back(to_string(a)+"->"+to_string(b));
            }
            i = j;
        }
        return ans;
    }
};