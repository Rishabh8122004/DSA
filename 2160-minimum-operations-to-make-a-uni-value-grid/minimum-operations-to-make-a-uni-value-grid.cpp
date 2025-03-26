class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int ans = INT_MIN;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                ans = max(ans,grid[i][j]);
            }
        }
        vector<pair<int,bool>> v(ans+1,{0,false});
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                v[grid[i][j]].second = true;
                v[grid[i][j]].first++;

            }
        }
        ans = INT_MAX;
        vector<int> ele;
        for(int i = 0;i<v.size();i++){if(v[i].second){while(v[i].first--){ele.push_back(i);}}}
        for(int i = ele.size()/2;i<ele.size() && i <= (ele.size()/2)+1;i++){
            int a = 0;bool flag = true;
            for(int j = 0;j<grid.size();j++){
                for(int k = 0;k<grid[j].size();k++){
                int d = ele[i]-grid[j][k];
                if(d%x != 0){flag = false;break;}
                d = abs(d);
                a+=(d/x);
                }
                if(!flag)break;
            }
            if(flag)ans = min(a,ans);
        }
        return ans == INT_MAX?-1:ans;
    }
};