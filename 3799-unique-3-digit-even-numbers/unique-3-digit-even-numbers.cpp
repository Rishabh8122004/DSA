class Solution {
public:
    int totalNumbers(vector<int>& d) {
        int n = d.size();
        vector<vector<int>>c;
        vector<int>v(3,1);
        for(int i = 0;i<n;i++){
            if(d[i] == 0)continue;
            v[0] = 1;
            v[0] = d[i];
            for(int j = 0;j<n;j++){
                v[1] = 1;
                if(j == i)continue;
                v[1] = d[j];
                for(int k = 0;k<n;k++){
                    v[2] = 1;
                    if(k == i || k == j || (d[k]%2 == 1))continue;
                    v[2] = d[k];
                    if(v[2] == 1)continue;
                    bool f = false;
                    for(int j = 0;j<c.size();j++){
                        if(c[j] == v){f = true;}
                    } 
                    if(!f)c.push_back(v);
                }
            }
        }
        for(int i = 0;i<c.size();i++){
            for(int j = 0;j<3;j++){
                cout<<c[i][j];
            }
            cout<<"   ";
        }
        return c.size();        
    }
};