class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>>p;
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; // minheap
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size();i++){
            if(p.empty() || p[p.size()-1].second != nums[i]){
                p.push_back({1,nums[i]});
            }
            else p[p.size()-1].first++;
        }
        for(int i = 0;i<p.size();i++){
            pq.push(p[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};