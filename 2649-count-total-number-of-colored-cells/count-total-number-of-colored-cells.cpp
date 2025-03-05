class Solution {
public:
    long long coloredCells(int n) {
        vector<long long int>v;
        v.push_back(1);
        v.push_back(5);
        v.push_back(13);
        if(n<=3) return v[n-1];
        n-=3;
        while(n--){
            v.push_back(v[v.size()-1]-v[v.size()-2]+4+v[v.size()-1]);
        }
        return v.back();
    }
};