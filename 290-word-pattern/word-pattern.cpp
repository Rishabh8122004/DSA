class Solution {
public:
    bool wordPattern(string p, string s) {
        vector<string>str;
        for(int i = 0;i<s.size();i++){
            string a = "";
            while(i<s.size() && s[i]!=' '){a+=s[i];i++;}
            str.push_back(a);
        }
        if(p.size()!=str.size())return false;
        vector<string>v(27,"");
        for(int i = 0;i<str.size();i++){
            if(v[p[i]-'a'] == ""){v[p[i]-'a']=str[i];}
            else if(v[p[i]-'a']!=str[i])return false;
        }
        sort(v.begin(),v.end());
        for(int i = 0;i<v.size()-1;i++){
            if(v[i] != "" && v[i] == v[i+1])return false;
        }
        return true;
    }
};