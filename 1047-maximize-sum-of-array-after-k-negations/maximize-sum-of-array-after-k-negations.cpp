class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i = 0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int a = pq.top();
        while(k--){
            a = pq.top();
            pq.pop();
            pq.push(a*-1);
        }
        int ans = 0;
        while(pq.size()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};