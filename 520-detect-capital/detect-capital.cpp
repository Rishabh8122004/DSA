class Solution {
public:
    bool detectCapitalUse(string w) {
        bool c = (w[0]>='a' && w[0]<='z')?false:true;
        for(int i = 1;i<w.size();i++){
            if(!c && w[i]>='A' && w[i]<='Z')return false;
            if(w[i]>='a' && w[i]<='z' && c && i>1)return false;
            if(w[i]>='a' && w[i]<='z')c = false;
        }
        return true;
    }
};