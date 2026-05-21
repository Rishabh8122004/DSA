class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string a = "";
        for(int i = 0;i<s.size();i++){
            if(s[i] != '-')a+=s[i];
        }
        s = "";
        int t = k;
        int i = a.size()-1;
        while(i>=0){
            if(a[i]>='a' && a[i]<='z'){
                a[i] = ('A' + a[i] - 'a');
            }
            s += a[i];
            i--;k--;
            if(k == 0 && i >= 0){
                k = t;
                s += '-';
            }
        }
        i = 0;
        int j = s.size()-1;
        while(i<j){
            swap(s[i],s[j]);
            i++;j--;
        }
        return s;
    }
};