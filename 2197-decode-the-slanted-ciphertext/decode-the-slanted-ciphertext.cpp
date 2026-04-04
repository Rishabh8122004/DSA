class Solution {
public:
    string decodeCiphertext(string e, int rows) {
        if(e == "")return "";
        int n = rows,m = e.size()/n;
        vector<vector<char>>v(n,vector<char>(m,' '));
        int k = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(e[k] != ' ')v[i][j] = e[k];
                k++;
            }
        }
        e = "";//using e as answer
        int j = 0;
        while(j<m){
            int i = 0;k = j;
            while(i<n && k<m){
              e+=v[i][k];
              i++;
              k++;
            }
            j++;
        }
        int len = e.size();
        while(e[len-1] == ' '){
            len--;
        }
        return e.substr(0,len);
    }
};