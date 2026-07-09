class Solution {
public:
    // int find(int x, vector<int>&parent){ // finding the parent of the node
    //     if(x == parent[x])return x;
    //     return find(parent[x],parent);
    // }
    // void union_(int x,int y,vector<int>&parent){ // join two nodes in one component
    //     int parent_x = find(x,parent);
    //     int parent_y = find(y,parent);
    //     if(parent_x != parent_y){
    //         parent[parent_x] = parent_y;
    //     }
    //     return;
    // }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& q) {
        vector<int>comp(n,-1); // compnent of each node
        int cmp = 0;
        comp[0] = 0;
        for(int i = 1;i<n;i++){
            if(abs(nums[i]-nums[i-1])<=maxDiff){
                comp[i] = comp[i-1];
            }
            else{
                cmp++;
                comp[i] = cmp;
            }
        }
        vector<bool>ans;
        for(int i = 0;i<q.size();i++){
            int x = q[i][0],y = q[i][1];
            if(comp[x] == comp[y]){
                ans.push_back(true);
            }
            else ans.push_back(false);
        }
        return ans;
    }
};