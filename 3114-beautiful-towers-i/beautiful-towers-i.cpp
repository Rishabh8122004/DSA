class Solution {
public:
    long long peekindex(vector<int> h,int idx){
        long long ans = 0;
        int n = h.size();
        int i = idx-1;
        while(i>=0){
            h[i] = min(h[i+1],h[i]);
            i--;
        }
        i = idx+1;
        while(i<n){
            h[i] = min(h[i],h[i-1]);
            i++;
        }
        for(int i = 0;i<n;i++){ans+=h[i];}
        return ans;
    }
    long long maximumSumOfHeights(vector<int>& h) {
        int n = h.size();
        int m = h[0];
        long long ans = 0;
        for(int i = 0;i<n;i++){m = max(m,h[i]);}
        for(int i = 0;i<n;i++){
            ans = max(ans,peekindex(h,i));
        }
        return ans;
    }
};