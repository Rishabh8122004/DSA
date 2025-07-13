class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>mp;
        for(int i = 0;i<arr1.size();i++){
            mp[arr1[i]]++;
        }
        vector<int>ans;
        for(int i = 0;i<arr2.size();i++){
            while(mp[arr2[i]]--){
                ans.push_back(arr2[i]);
            }
            mp.erase(arr2[i]);
        }
        if(mp.size()){
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto p :mp){
            while(p.second--) pq.push(p.first);
        }
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        }
        return ans;
    }
};