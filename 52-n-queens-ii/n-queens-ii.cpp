class Solution {
public:
    unordered_map<int,int>row;
    unordered_map<int,int>col;
    unordered_map<int,int>diag1;
    unordered_map<int,int>diag2;
    int ans = 0;
    void solve(int r,int c,int Q,int& n){
        if(r == n){
            if(Q == n){ans++;}
            return ;
        }
        if(c == n){
            solve(r+1,0,Q,n);
            return;
        }
        if(row[r] == 0 && col[c] == 0 && diag1[r-c] == 0 && diag2[r+c] == 0 && Q < n){
            row[r] = 1;
            col[c] = 1;
            diag1[r-c] = 1;
            diag2[r+c] = 1;
            solve(r,c+1,Q+1,n);
            diag1[r-c] = 0;
            diag2[r+c] = 0;
            row[r] = 0;
            col[c] = 0;
        }
        solve(r,c+1,Q,n);
        return;
    }
    int totalNQueens(int n) {
        if(n == 1)return 1;
        solve(0,0,0,n);
        return ans;
    }
};