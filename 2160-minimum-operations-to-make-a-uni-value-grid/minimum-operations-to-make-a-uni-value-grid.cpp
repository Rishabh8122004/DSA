class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int ans = INT_MAX;
        vector<int> v;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                v.push_back(grid[i][j]);
            }
        }
        sort(v.begin(),v.end());
        for(int i = v.size()/2;i<v.size() && i <= (v.size()/2)+1;i++){
            int a = 0;
            bool flag = true;
            for(int j = 0;j<v.size();j++){
                int d = v[i]-v[j];
                if(d%x != 0){flag = false;break;}
                d = abs(d);
                a+=(d/x);
            }
            if(flag)ans = min(a,ans);
        }
        return ans == INT_MAX?-1:ans;
    }
};