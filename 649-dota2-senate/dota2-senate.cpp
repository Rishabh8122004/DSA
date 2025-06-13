class Solution {
public:
    string predictPartyVictory(string s) {
        queue<int>r,d;
        for(int i = 0;i<s.size();i++){
            if(s[i] == 'R')r.push(i);
            else d.push(i);
        }
        while(!r.empty() && !d.empty()){
            for(int i = 0;i<s.size();i++){
                if(r.empty() || d.empty())break;
                if(s[i] == '0')continue;
                if(s[i] == 'R' && !r.empty()){
                    s[d.front()] = '0';
                    d.pop();
                    r.push(r.front());
                    r.pop();
                }
                else if(s[i] == 'D' && !d.empty()){
                    s[r.front()] = '0';
                    r.pop();
                    d.push(d.front());
                    d.pop();
                }
            }
        }
        if(d.empty())return "Radiant";
        return "Dire";
    }
};