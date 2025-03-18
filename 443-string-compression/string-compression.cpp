class Solution {
public:
    string append(int x){
        string s = "";
        while(x>0){
            s+=(char(x%10)+'0');
            x/=10;
        }
        int i = 0,j = s.size()-1;
        while(i<j){swap(s[i],s[j]);i++;j--;}
        return s;
    }
    int compress(vector<char>& chars) {
        string s = "";
        for(int i = 0;i<chars.size();i++){
            int c = 1;
            while(i<chars.size()-1 && chars[i] == chars[i+1]){
                c++;
                i++;
            }
            s+=chars[i];
            if(c>1) s+=append(c);
        }
        for(int i = 0;i<s.size();i++){
            chars[i] = s[i];
        }
        return s.size();
    }
};