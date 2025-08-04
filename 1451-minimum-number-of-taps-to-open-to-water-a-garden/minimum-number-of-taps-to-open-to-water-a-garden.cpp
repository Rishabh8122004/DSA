class Solution {
public:
    map<pair<int,int>,int>mp;
    int solve(vector<vector<int>>&r,int i,int maxend){
        if(i>=r.size()){
            if(maxend>=r.size()-1)return 0;
            else return 1e9;
        }
        if(r[i][0]>maxend)return 1e9;
        if(mp.find({i,maxend}) != mp.end())return mp[{i,maxend}];
        int open = 1+solve(r,i+1,max(maxend,r[i][1]));
        int not_open = solve(r,i+1,maxend);
        return mp[{i,maxend}] =  min(open,not_open);
    }
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>>r;
        for(int i = 0;i<ranges.size();i++){
            int start = max(0,i-ranges[i]);
            int end = min(n,i+ranges[i]);
            r.push_back({start,end});
        }
        sort(r.begin(),r.end());
        int ans = solve(r,0,0);
        return ans == 1e9?-1:ans;
    }
};