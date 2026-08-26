class Solution {
public:
    string cmp_str(string a,string b){
        for(int i = 0;i<a.size();i++){
            if(a[i]<b[i])return a;
            if(b[i]<a[i])return b;
        }
        return b;
    }
    string shortestBeautifulSubstring(string s, int k) {
        int len = 0;
        string ans = "";
        int i = 0,j = 0;
        int noo = 0;
        while(j<s.size()){
            if(s[j] == '1')noo++;
            while((len && ((j-i+1) > len)) || (noo > k) || (s[i] == '0')){
                if(s[i] == '1')noo--;
                i++;
            }
            if(noo == k){
                if(len == 0){ // first beautifull substring
                    len = (j-i+1);
                    ans = s.substr(i,len);
                }
                else if((j-i+1)<len){ // smaller in length
                    len = (j-i+1);
                    ans = s.substr(i,len);
                }
                else if(len == (j-i+1)){ // lexographicaly smaller
                    ans = cmp_str(s.substr(i,len),ans);
                }
            }
            j++;
        }
        return ans;
    }
};