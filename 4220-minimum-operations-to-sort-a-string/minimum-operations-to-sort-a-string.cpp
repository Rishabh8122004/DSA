class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        bool sorted = true;
        int mi = 0,ma = 0; // index of minimum and maximum characters in s
        for(int i = 0;i<n;i++){
            if(i+1 < n && s[i+1] < s[i]){
                sorted = false;
            }
            if(s[i] < s[mi])mi = i;
            if(s[i] >= s[ma])ma = i;
        }
        cout<<mi<<" "<<ma;
        if(sorted)return 0;
        if(n == 2)return -1; // cannot sort this one
        if(mi == 0 || ma == n-1)return 1;
        if(mi == n-1 && ma == 0)return 3;
        return 2;
    }
};