class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int ans = INT_MAX;
        for(int i = 1;i<arr.size();i++){
            ans = min(ans,arr[i]-arr[i-1]);
        }
        vector<vector<int>>v;
        for(int i = 1;i<arr.size();i++){
            if(arr[i]-arr[i-1] == ans){
                v.push_back({arr[i-1],arr[i]});
            }
        }
        return v;
    }
};