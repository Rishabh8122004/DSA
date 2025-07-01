class Solution {
public:
    int possibleStringCount(string w) {
        int ans = 1;
        for(int i = 1;i<w.size();i++){
            if(w[i] == w[i-1])ans++;
        }
        return ans;
    }
};