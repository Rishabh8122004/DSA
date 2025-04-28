class Solution {
public:
    bool isvalid(vector<vector<char>>& b, string &w,int i,int j,string s,vector<vector<bool>>&v){
        if(s.size() == w.size()){ return s == w;}
        if(s[s.size()-1] != w[s.size()-1]){return false;}
        if(i>0 && !v[i-1][j]){
            v[i-1][j] = true;
            if(isvalid(b,w,i-1,j,s+b[i-1][j],v)) return true;
            else v[i-1][j] = false;
        }
        if(j<b[0].size()-1 && !v[i][j+1]){
            v[i][j+1] = true;
            if(isvalid(b,w,i,j+1,s+b[i][j+1],v)) return true;
            else v[i][j+1] = false;
        }
        if(i<b.size()-1 && !v[i+1][j]){
            v[i+1][j] = true;
            if(isvalid(b,w,i+1,j,s+b[i+1][j],v)) return true;
            else v[i+1][j] = false;
        }
        if(j>0 && !v[i][j-1]){
            v[i][j-1] = true;
            if(isvalid(b,w,i,j-1,s+b[i][j-1],v)) return true;
            else v[i][j-1] = false;
        }
        return false;
    }
    bool exist(vector<vector<char>>& b, string w) {
        if(w.size()>(b.size()*b[0].size())) return false;
        vector<vector<bool>>v(b.size(),vector<bool>(b[0].size()));
        string s;
        for(int i = 0;i<b.size();i++){
            for(int j = 0;j<b[i].size();j++){
                s = b[i][j];
                v[i][j] = true;
                if(isvalid(b,w,i,j,s,v)){return true;}
                else v[i][j] = false;
            }
        }
        return false;
    }
};