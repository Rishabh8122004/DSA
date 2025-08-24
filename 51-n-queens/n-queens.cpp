class Solution {
public:
    unordered_map<int,int>row;
    unordered_map<int,int>col;
    unordered_map<int,int>diag1;
    unordered_map<int,int>diag2;
    vector<vector<string>>ans;
    bool solve(vector<string>&v,int r,int c,int Q,int& n){
        if(r == n){
            if(Q == n){ans.push_back(v);return true;}
            else return false;
        }
        if(c == n){
            return solve(v,r+1,0,Q,n);
        }
        if(row[r] == 0 && col[c] == 0 && diag1[r-c] == 0 && diag2[r+c] == 0 && Q < n){
            v[r][c] = 'Q';
            row[r] = 1;
            col[c] = 1;
            diag1[r-c] = 1;
            diag2[r+c] = 1;
            if(!solve(v,r,c+1,Q+1,n)){
                v[r][c] = '.';
            }
            diag1[r-c] = 0;
            diag2[r+c] = 0;
            row[r] = 0;
            col[c] = 0;
        }
        v[r][c] = '.';
        return solve(v,r,c+1,Q,n);
    }
    vector<vector<string>> solveNQueens(int n) {
        if(n == 1)return {{"Q"}};
        vector<string>v;
        string s = "";
        for(int j = 0;j<n;j++)s+='.';
        for(int i = 0;i<n;i++){
            v.push_back(s);
        }
        solve(v,0,0,0,n);
        return ans;
    }
};