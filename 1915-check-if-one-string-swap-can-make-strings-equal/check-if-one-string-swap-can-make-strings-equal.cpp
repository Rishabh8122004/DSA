class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        int count = 0;
        char a;
        for(int i = 0;i<n;i++){
            if(s1[i]!=s2[i]){
                count++;
                if(count == 1){a = s1[i];}
                if(count == 2 && s2[i]!=a){return false;}
                if(count>2)return false;
            }
        }
        vector<int>v(26,0);
        for(int i = 0;i<n;i++){
            v[s1[i]-'a']++;
            v[s2[i]-'a']--;
        }
        for(int i = 0;i<26;i++){
            if(v[i]>0 || v[i]<0)return false;
        }
        return true;
    }
};