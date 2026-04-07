class Solution {
public:
    vector<int>v;
    void solve(vector<vector<int>>&ans,int i,int &n,int &k){
        if(i>n){
            if(v.size() == k)ans.push_back(v);
            return;
        }
        v.push_back(i);
        solve(ans,i+1,n,k);
        v.pop_back();
        solve(ans,i+1,n,k);
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        solve(ans,1,n,k);
        return ans;
    }
};