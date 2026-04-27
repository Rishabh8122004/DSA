class Solution {
public:
    int v[305][305];
    bool solve(vector<vector<int>>& g,int i,int j,char d,int &n,int &m){
        if(i == n-1 && j == m-1){
            if(g[i][j] == 1){
                return (d == 'r'); // you can only come from right
            }
            if(g[i][j] == 2){
                return (d == 'd'); // you can only come from up means you went down to reach this cell
            }
            if(g[i][j] == 3){
                return (d == 'r'); // you can only come from right
            }
            if(g[i][j] == 4){
                return false; // there is no way you can reach this cell if street is 4
            }
            if(g[i][j] == 5){
                return (d == 'r' || d == 'd'); // you can come from right or come from up to reach this cell
            }
            if(g[i][j] == 6){
                return (d == 'd'); // you can only reach this cell if you went down
            }
        }
        if(i<0 || i>=n || j<0 || j>=m)return false;
        if(v[i][j] == 1)return false;
        v[i][j] = 1;
        if(d == 'n'){ // means we are at i = 0 & j = 0
            if(g[i][j] == 1){
                return solve(g,i,j-1,'l',n,m) || solve(g,i,j+1,'r',n,m); // moving left or right
            }
            if(g[i][j] == 2){
                return solve(g,i-1,j,'u',n,m) || solve(g,i+1,j,'d',n,m); // moving up or down
            }
            if(g[i][j] == 3){
                return solve(g,i,j-1,'l',n,m) || solve(g,i+1,j,'d',n,m); // moving left or down
            }
            if(g[i][j] == 4){
                return solve(g,i+1,j,'d',n,m) || solve(g,i,j+1,'r',n,m); // moving down or right
            }
            if(g[i][j] == 5){
                return solve(g,i,j-1,'l',n,m) || solve(g,i-1,j,'u',n,m); // moving left or up
            }
            if(g[i][j] == 6){
                return solve(g,i-1,j,'u',n,m) || solve(g,i,j+1,'r',n,m); // moving up or right
            }
        }
        else{
            if(g[i][j] == 1){
                if(d == 'r')return solve(g,i,j+1,'r',n,m); // coming from left !! ,  go right
                else if(d == 'l')return solve(g,i,j-1,'l',n,m); // coming from right !! , go left
                else return false;
 
            }
            if(g[i][j] == 2){
                if(d == 'u')return solve(g,i-1,j,'u',n,m); // coming up !! ,  go up
                else if(d == 'd')return solve(g,i+1,j,'d',n,m); // coming down !! , go down
                else return false;
            }
            if(g[i][j] == 3){
                if(d == 'r')return solve(g,i+1,j,'d',n,m); // coming from left !! ,  go down
                else if(d == 'u')return solve(g,i,j-1,'l',n,m); // coming up !! , go left
                else return false;
            }
            if(g[i][j] == 4){
                if(d == 'u')return solve(g,i,j+1,'r',n,m); // coming up !! ,  go right
                else if(d == 'l')return solve(g,i+1,j,'d',n,m); // coming from right !! , go down
                else return false;
            }
            if(g[i][j] == 5){
                if(d == 'r')return solve(g,i-1,j,'u',n,m); // coming from left !! ,  go up
                else if(d == 'd')return solve(g,i,j-1,'l',n,m); // coming down !! , go left
                else return false;
            }
            if(g[i][j] == 6){
                if(d == 'd')return solve(g,i,j+1,'r',n,m); // coming down !! ,  go right
                else if(d == 'l')return solve(g,i-1,j,'u',n,m);  // coming from right !! , go up
                else return false;
            }
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        memset(v,0,sizeof(v));
        if(n == 1 && m == 1)return true;
        char d = 'n'; // no previous direction
        return solve(g,0,0,d,n,m);
    }
};