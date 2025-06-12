class Solution {
public:
    void check(vector<vector<int>>& ans){
        int n = ans.size();
        if(ans.size()>1){
            if(ans[n-1][0]<=ans[n-2][0] || ans[n-1][1] <= ans[n-2][1]){
                swap(ans[n-2],ans[n-1]);
                ans.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> insert(vector<vector<int>>& iv, vector<int>& niv) {
        iv.push_back(niv);
        vector<vector<int>> ans;
        int n = iv.size();
        if(n == 1)return iv;
        sort(iv.begin(),iv.end());
            for(int i = 0;i<n;i++){
                bool f = true;
                if(i == 1 && ans.empty()){ans.push_back(iv[0]);}
                if(i<n-1 && iv[i][1] >= iv[i+1][0]){
                    iv[i][1] = max(iv[i][1],iv[i+1][1]);
                    ans.push_back({iv[i][0],iv[i][1]});
                    iv[i+1] = iv[i];
                    f = false;
                }
                else if(i>0 && iv[i][0]<=iv[i-1][1]){
                    iv[i][0] = min(iv[i][0],iv[i-1][0]);
                    ans.push_back(iv[i]);
                    f = false;
                }
                if(f && !ans.empty() && ans[ans.size()-1] != iv[i]){
                ans.push_back({iv[i]});
                }
                check(ans);
            }
        return ans;
    }
};