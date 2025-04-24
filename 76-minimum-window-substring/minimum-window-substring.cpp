class Solution {
public:
    string minWindow(string s, string t) {
        if(s == t)return s;
        if(s.size()<t.size())return "";
        vector<int>v(128,0); // full ascii range
        for(int i = 0;i<t.size();i++){v[t[i]]++;}
        int tw = t.size();
        int i = 0,j = 0;
        string ans = s;
        while(j<s.size()){
            while(j<s.size() && tw>0){if(v[s[j]] > 0)tw--;v[s[j]]--;j++;if(tw == 0)j--;}
            if(tw!=0 && ans == s &&j>=s.size())return "";
            while(tw == 0){v[s[i]]++;if(v[s[i]]>0)tw++;i++;if(tw==1){i--;v[s[i]]--;tw--;break;}}
            if(tw == 0 && ans.size()>(j-i+1)){ans = s.substr(i,j-i+1);}
            if(ans == t)return ans;
            v[s[i]]++;
            if(v[s[i]]>0)tw++;
            i++;
            j++;
        }
        return ans;
    }
};