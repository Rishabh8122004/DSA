class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        stack<char>t;
        string p = "";
        vector<vector<int>> v(26);
        for (int i = 0; i < n; i++) {
            v[s[i] - 'a'].push_back(i);
        }
        int j = 0;
        for(int i = 0;i<26;i++){
            if(v[i].empty())continue;
            while(!v[i].empty() && j>v[i][0]){v[i].erase(v[i].begin());}
            if(v[i].empty())continue;
            while(!t.empty() && t.top()<=('a'+i)){p+=t.top();t.pop();}
            while(!v[i].empty()){
                if(j>v[i][0]){v[i].erase(v[i].begin());continue;}
                while(j<=v[i][0]){
                    t.push(s[j]);
                    j++;
                }
                while(!t.empty() && t.top() == ('a'+i)){p+=t.top();t.pop();}
            }
        }
        while(!t.empty()){
            p+=t.top();
            t.pop();
        }
        return p;
    }
};