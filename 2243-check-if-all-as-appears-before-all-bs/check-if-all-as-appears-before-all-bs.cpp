class Solution {
public:
    bool checkString(string s) {
        bool b = false;
        for(char & ch : s){
            if(ch == 'b')b = true;
            if(b && (ch == 'a'))return false;
        }
        return true;
    }
};