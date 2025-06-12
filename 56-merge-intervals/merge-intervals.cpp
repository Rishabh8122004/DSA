class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& iv) {
        vector<vector<int>> ans;
        int n = iv.size();
        sort(iv.begin(),iv.end());
        bool f = false;
        while(!f){
            f = true;
            for(int i = 0;i<n;i++){
                if(i<n-1 && iv[i][1] >= iv[i+1][0]){
                    iv[i][1] = max(iv[i][1],iv[i+1][1]);
                    ans.push_back({iv[i][0],iv[i][1]});
                    f = false;
                    i++;
                    continue;
                }
                ans.push_back({iv[i][0],iv[i][1]});
            }
            iv = ans;
            n = iv.size();
            ans = {};
        }
        return iv;
    }
};