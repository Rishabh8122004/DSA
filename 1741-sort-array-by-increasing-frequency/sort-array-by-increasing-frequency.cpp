class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<pair<int,int>>p;
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; // minheap
        sort(nums.begin(),nums.end()); //sorting first then we gonna put then in the form of pair
        for(int i = 0;i<nums.size();i++){
            if(p.empty() || p[p.size()-1].second != nums[i]){
                p.push_back({1,nums[i]});
            }
            else p[p.size()-1].first++;
        }
        for(int i = 0;i<p.size();i++){
            pq.push(p[i]);
        }
        vector<vector<int>>freq(101,vector<int>(0));
        while(pq.size()){
            freq[pq.top().first].push_back(pq.top().second);
            pq.pop();
        }
        for(int i = 0;i<freq.size();i++){
            if(freq[i].size()>1){
                sort(freq[i].begin(),freq[i].end());
            }
            for(int j=freq[i].size()-1;j>=0;j--){
                int k = i;
                while(k--){
                ans.push_back(freq[i][j]);
                }
            }
        }
        return ans;
    }
};