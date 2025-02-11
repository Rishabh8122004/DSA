class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = part.size();
        bool flag = false;
        while(true &&  s.size() >= part.size() ){
            flag = false;
        for(int i = 0;i<s.size()-n+1;i++){
            if(part == s.substr(i,n)) 
            {
                s.erase(i,n); 
                flag = true;
                break;
            }
        }
        if(!flag || s.size() < part.size()) break;
        }
        return s;
    }
};