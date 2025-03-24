class Solution {
public:
    string addBinary(string a, string b) {
        char c = '0';
        string ans = "";
        int i = a.size()-1,j = b.size()-1;
        while(i>=0||j>=0){
            char x = '0';
            if(i>=0 && j>=0){
                if(a[i] == '1' && b[j] == '1'){ x = (c == '1'?'1':'0');c = '1';}
                else if(a[i] == '0' && b[j] == '0'){ x = (c == '1'?'1':'0');c = '0';}
                else if(a[i] == '1' || b[j] == '1'){ x = (c == '1'?'0':'1');}
                i--;j--;
            }
            else if(i>=0){
                if(a[i] == '1'){x = (c == '1'?'0':'1');}
                else if (a[i] == '0'){ x = (c == '1'?'1':'0');c = '0';}
                i--;
            }
            else if(j>=0){
                if(b[j] == '1'){x = (c == '1'?'0':'1');}
                else if (b[j] == '0'){ x = (c == '1'?'1':'0');c = '0';}
                j--;
            }
            ans = x+ans;
        }
        if(c == '1'){ans = c+ans;}
        return ans;
    }
};