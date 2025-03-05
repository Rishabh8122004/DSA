class Solution {
public:
    bool solve(int n,vector<bool>&v){
        if(n == 0)return true;
        int x = 0, y = 1;
        while(y*3<=n){
            y*=3;
            x++;
        }
        if(v[x] == true)return false;
        else v[x] = true;
        return solve(n-y,v);
    }
    bool checkPowersOfThree(int n) {
        vector<bool>v(20,false);
        return solve(n,v);
    }
};