class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
        int n = gs.size();
       vector<vector<int>>v(n+1);
       vector<vector<int>>ans;
       for(int i = 0;i<gs.size();i++){
        v[gs[i]].push_back(i);
       } 
       for(int i = 1;i<v.size();i++){
        while(v[i].size()){
            vector<int>p;
            while(p.size()<i){
                p.push_back(v[i].back());
                v[i].pop_back();
            }
            ans.push_back(p);
        }
       }
       return ans;
    }
};