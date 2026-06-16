class Solution {
public:
    void reverse(string &result){
        int i = 0,j = result.size()-1;
        while(i<j){
            swap(result[i],result[j]);
            i++;j--;
        }
        return;
    }
    char processStr(string s, long long k) {
        long long l = 0;
        for(auto ch:s){
            if(ch == '*' && l>0){
                l--;
            }
            else if(ch == '#'){
                l*=2;
            }
            else if(ch == '%'){
                continue;
            }
            else if(ch>='a' && ch<='z')l++;
        }
        if(k>=l)return '.';
        for(int i = s.size()-1;i>=0;i--){
            char ch = s[i];
            if(ch == '*' && l>0){
                l++;
            }
            else if(ch == '#'){
                l/=2;
                if(k>=l) k-=l;
            }
            else if(ch == '%'){
                k = l-1-k;
            }
            else if(ch>='a' && ch<='z'){
                l--;
                if(l == k)return ch;
            }
        }
        return '.';
    }
};