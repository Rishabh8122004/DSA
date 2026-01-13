class Solution {
public:
    double getarea(double mid,vector<vector<int>>& s){
        long double x = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i][1] < mid ){
                if(s[i][1]+s[i][2]>mid){
                    x += (long double)(mid-s[i][1])*s[i][2];
                }
                else x += (long double)s[i][2]*s[i][2];
            }
        }
        return x;
    }
    double separateSquares(vector<vector<int>>& s) {
        int n = s.size();
        long double ta = 0;//total area
        double lo = s[0][1],hi = s[0][1];
        for(int i = 0;i<n;i++){
            lo = min(lo,(double)s[i][1]);
            hi = max(hi,(double)s[i][1]+s[i][2]);
            ta += ((long double)s[i][2]*s[i][2]);
        }
        double mid;
        long double x ;
        while(lo<=hi){
            mid = lo+(hi-lo)/2;
            x = getarea(mid,s);// getting area below the middle line
            if(x >= (ta-x))hi = mid-0.00001;
            else lo = mid+0.00001;
        }
        return lo;
    }
};