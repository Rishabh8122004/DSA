class Solution {
public:
    void solve(int i,string s,int &n,int k,vector<string> &ans){
        if(s.size() == n){
            ans.push_back(s);
            return;
        }
        solve(i+1,s+'0',n,k,ans);
        if(k>=i){
            if(s.empty() || (s[s.size()-1] != '1')){
                solve(i+1,s+'1',n,k-i,ans);
            }
        }
        return;
    }
    vector<string> generateValidStrings(int n, int k) {
        vector<string>ans;
        solve(0,"",n,k,ans);
        return ans;
    }
};