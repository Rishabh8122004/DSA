class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())return 0;
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(goal[0] == s[i]){
               if((s.substr(i,n-i) == goal.substr(0,n-i)) && (s.substr(0,i) == goal.substr(n-i,n-(n-i)))) return true;
            }
        }
        return false;
    }
};