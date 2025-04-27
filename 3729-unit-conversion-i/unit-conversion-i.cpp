class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& c) {
        int n = c.size();
        int m = 0;
        for(int i = 0;i<n;i++){
            if(m<c[i][1])m = c[i][1];
        }
        vector<long long >v(m+1);
        v[0] = 1;
        for(int i = 0;i<n;i++){
            v[c[i][1]] += ((v[c[i][0]]%1000000007)*(c[i][2]%1000000007)); 
        }
        vector<int> ans;
        for(int i = 0;i<v.size();i++){
            if(v[i]!=0)ans.push_back((v[i])%1000000007);
        }
        return ans;
    }
};