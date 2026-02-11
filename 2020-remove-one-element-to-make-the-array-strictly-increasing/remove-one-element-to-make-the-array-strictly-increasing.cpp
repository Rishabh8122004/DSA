class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int c = 0;
        stack<int>st;
        int i = 1;
        st.push(nums[0]);
        while(i<nums.size()){
            while(!st.empty()&&st.top()>=nums[i]){
                if(i<nums.size()-1 && nums[i+1]<=st.top())st.pop();
                else i++;
                c++;
                if(i == nums.size())break;
                }
            if(i == nums.size())break;
            st.push(nums[i]);
            if(c==2)return false;
            i++;
        }
        return c<=1;
    }
};