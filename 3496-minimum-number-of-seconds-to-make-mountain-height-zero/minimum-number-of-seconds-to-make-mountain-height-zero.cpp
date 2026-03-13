class Solution {
public:
    bool is_valid(long mid,int h,vector<int>&wt){
        for(int i = 0;i<wt.size();i++){
            long long j = (-1 + sqrt(1 + 8 * mid / wt[i])) / 2;
            h -= j;
            if(h<=0)return  true;
        }
        return h <= 0;
    }
    long long minNumberOfSeconds(int h, vector<int>& wt) {
        sort(wt.begin(),wt.end());
        long ans = (wt[0]*((1LL*h*(h+1))/2));
        long lo = 1,hi = ans;
        while(lo<=hi){
            long mid = lo+(hi-lo)/2;
            if(is_valid(mid,h,wt)){hi = mid-1;ans = min(ans,mid);}
            else lo = mid+1;
        }
        return ans;
    }
};