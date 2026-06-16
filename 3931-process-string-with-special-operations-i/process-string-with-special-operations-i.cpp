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
    string processStr(string s) {
        string result = "";
        for(auto ch:s){
            if(ch == '*' && !result.empty()){
                result.pop_back();
            }
            else if(ch == '#'){
                result += result;
            }
            else if(ch == '%'){
                reverse(result);
            }
            else if(ch>='a' && ch<='z')result += ch;
        }
        return result;
    }
};