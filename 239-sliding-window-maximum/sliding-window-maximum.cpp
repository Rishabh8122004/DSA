class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>nge(n,-100000);
        stack<int>st;
        st.push(-100000);
        for(int i = n-2;i>=0;i--){
            st.push(i+1);
            while(st.size()>1 && nums[i]>nums[st.top()]){st.pop();}
            nge[i] = st.top();
        }
        vector<int>ans;
        for(int i = 0;i<n-k+1;i++){
            int x = i;
            while(nge[x]!=-100000 && nge[x]<i+k)x = nge[x];
            ans.push_back(nums[x]);
        }
        return ans;
    }
};