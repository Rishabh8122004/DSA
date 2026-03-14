class Solution {
public:
    string ans = "";
    void solve(int &n,int &k,string s){
        if(s.size() == n){
            k--;
            if(k == 0)ans = s;
            return;
        }
        if(s.empty() || s.back() != 'a')solve(n,k,s+'a');
        if(s.empty() || s.back() != 'b')solve(n,k,s+'b');
        if(s.empty() || s.back() != 'c')solve(n,k,s+'c');
        return;
    }
    string getHappyString(int n, int k) {
        if(k>(3*pow(2,n-1)))return ""; // k is greater than number of strings we can generate using n spaces.
        solve(n,k,"");
        return ans;
    }
};