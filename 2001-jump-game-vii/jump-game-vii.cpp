class Solution {
public:
    bool canReach(string s, int mi, int ma) {
        int n = s.size();
        vector<int>v(n,0);
        v[0] = 1;
        int count = 0;
        for(int i = 1;i<n;i++){
            if(i-mi>=0){
                if(v[i-mi]>0)count += v[i-mi];
            }
            if(i-ma-1>=0){
                if(v[i-ma-1] > 0)count -= v[i-ma-1];
            }
            if(count > 0 && s[i] == '0')v[i] = 1;
        }
        return v[n-1] > 0;
    }
};