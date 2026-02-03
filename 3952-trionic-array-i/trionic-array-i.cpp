
class Solution {
public:
    bool isTrionic(vector<int>& v) {
        int n = v.size();
        int p = 0,q = 1;
        while(v[p]<v[p+1]){
            p++;
            if(p == n-1)return false;
        }
        q = p+1;
        if(v[q]>=v[p])return false;
        if(p == 0 || q == n-1)return false;
        while(v[q]>v[q+1]){
            q++;
            if(q == n-1)return false;
        }
        cout<<p<<" "<<q;
        int i = q;
        while(i<n-1){
            if(v[i]>=v[i+1])return false;
            i++;
        }
        return true;
    }
};