class Solution {
public:
    int pivotInteger(int n) {
        int lo = 1,hi = n,s1,s2;
        while(lo<=hi){
            int m = (lo+hi)/2;
            s1 = (m*(m+1))/2;
            s2 =  ((n*(n+1))/2)-(((m-1)*m)/2);
            if(s1 == s2) return m;
            else if(s1 > s2) hi = m-1;
            else lo = m+1;
            cout<<s1<<" "<<s2<<"   "<<m;
        }
        return -1;
    }
};