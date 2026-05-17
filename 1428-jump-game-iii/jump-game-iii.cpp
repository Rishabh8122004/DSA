class Solution {
public:
    int vis[50005];
    bool solve(int start,vector<unordered_map<int,int>>&graph,vector<int>& arr){
        if(vis[start] == 1)return false;
        vis[start] = 1;
        if(arr[start] == 0)return true;
        for(auto & p: graph[start]){
            if(arr[p.first] == 0)return true;
            if(solve(p.first,graph,arr))return true;
        }
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<unordered_map<int,int>>graph(arr.size()+1);// connected indices
        memset(vis,0,sizeof(vis));//visited array
        for(int i = 0;i<arr.size();i++){
            if(i-arr[i]>=0){
                graph[i][i-arr[i]] = 1;
            }
            if(i+arr[i] < arr.size()){
               graph[i][i+arr[i]] = 1;
            }
        }
        return solve(start,graph,arr);
    }
};