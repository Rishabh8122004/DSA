class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& b, int n) {
        vector<int> v(n+1);
        for(int i = 0;i<b.size();i++){
            v[b[i][0]-1]+=b[i][2];
            v[b[i][1]]-=b[i][2];
        }
        for(int i = 1;i<v.size();i++){v[i]+=v[i-1];}
        v.pop_back();
        return v;
    }
};