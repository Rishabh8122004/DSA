class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        int n = p.size();
        vector<bool>vis(n,0); // meaning the ballon is already popped
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>min_end,min_start;
        for(int i = 0;i<n;i++){
            min_end.push({p[i][1],i});
            min_start.push({p[i][0],i});
        }
        int ans = 0;
        while(!min_end.empty()){
            if(vis[min_end.top().second]){
                min_end.pop();
                continue;
            }
            ans++;
            while(min_start.size()){
                if(vis[min_start.top().second])min_start.pop();
                else if(min_start.top().first <= min_end.top().first){
                    vis[min_start.top().second] = true;
                    min_start.pop();
                }
                else break;
            }
        }
        return ans;
    }
};