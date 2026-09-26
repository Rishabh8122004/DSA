class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {
        unordered_map<string,string>mp;
        for(int i = 0;i<k.size();i++){
            mp[k[i][0]] = k[i][1];
        }
        string ans = "";
        int i = 0;
        while(i<s.size()){
            if(s[i] == '('){
                int j = i+1;
                while(j<s.size() && s[j] != ')'){
                    j++;
                }
                string t = s.substr(i+1,j-i-1);
                if(mp.count(t) == 0)ans += "?";
                else ans += mp[t];
                i = j;
            }else{
                ans += s[i];
            }
            i++;
        }
        return ans;
    }
};