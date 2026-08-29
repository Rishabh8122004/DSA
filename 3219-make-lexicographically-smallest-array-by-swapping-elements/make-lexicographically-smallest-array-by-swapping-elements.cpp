class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<vector<int>>v;
        for(int i = 0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        unordered_map<int, priority_queue<int>*>mp;// every index in this map points to it's dedicated vector of elements that can be swaped with it
        priority_queue<int>*pq = new(priority_queue<int>);
        pq->push(v[0][0]);
        mp[v[0][1]] = pq;
        for(int i = 1;i<n;i++){
            if(abs(v[i][0]-v[i-1][0]) <= limit){
                pq->push(v[i][0]);
            }else{
                pq = new(priority_queue<int>);
                pq->push(v[i][0]);
            }
            mp[v[i][1]] = pq;
        }
        for(int i = n-1;i>=0;i--){
            nums[i] = mp[i]->top();
            mp[i]->pop();
        }
        return nums;
    }
};