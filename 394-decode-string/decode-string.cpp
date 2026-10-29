class Solution {
public:
    string decodeString(string s) {
        string ans = "";
        int n = s.size();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') { // decoding number
                string x = "";
                x+=s[i];
                int j = i+1;
                while ((j < n) && (s[j] >= '0' && s[j] <= '9')) {
                    x += s[j];
                    j++;
                }
                int num = stoi(x);
                x = "";
                int noo = 1;
                j++;
                while(j<n && noo){
                    if(s[j] == '[')noo++;
                    else if(s[j] == ']')noo--;
                    if(noo)x+=s[j];
                    j++;
                }
                i = j-1;
                //cout<<num<<"  "<<x<<endl;
                x = decodeString(x); // recursion used here
                while(num--){
                    ans += x;
                }
            }
            else ans += s[i];
        }
        return ans;
    }
};