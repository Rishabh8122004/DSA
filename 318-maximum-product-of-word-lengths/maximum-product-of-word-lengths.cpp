class Solution {
public:
    int maxProduct(vector<string>& w) {
        vector<vector<int>>v(w.size(),vector<int>(26,0));
        for(int i = 0;i<w.size();i++){
            for(int j = 0;j<w[i].size();j++){
                v[i][w[i][j]-'a'] = 1;
            }
        }
        int ans = 0;
        bool f = true;
        for(int i = 0;i<w.size();i++){
            for(int j = i+1;j<w.size();j++){
                f = true;
                for(int k = 0;k<26;k++){
                    if(v[j][k] == 1 && v[i][k] == 1){f = false;break;}
                }
                if(f){
                    if(ans<(w[i].size()*w[j].size())){
                        ans = (w[i].size()*w[j].size());
                    }
                }
            }
        }
        return ans;
    }
};