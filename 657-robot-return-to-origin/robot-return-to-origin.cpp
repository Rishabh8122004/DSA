class Solution {
public:
    bool judgeCircle(string m) {
        stack<char>v,h;
        for(int i = 0;i<m.size();i++){
            if(m[i] == 'L' || m[i] == 'R'){
                if(h.empty()){
                    h.push(m[i]);
                }
                else{
                    if(m[i] == 'L' && h.top() == 'R'){
                        h.pop();
                    }
                    else if(m[i] == 'R' && h.top() == 'L')h.pop();
                    else h.push(m[i]);
                }
            }
            else if(m[i] == 'U' || m[i] == 'D'){
                if(v.empty()){
                    v.push(m[i]);
                }
                else{
                    if(m[i] == 'U' && v.top() == 'D'){
                        v.pop();
                    }
                    else if(m[i] == 'D' && v.top() == 'U')v.pop();
                    else v.push(m[i]);
                }
            }
        }
        return h.empty() && v.empty();
    }
};