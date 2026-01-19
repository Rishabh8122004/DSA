class Solution {
public:
    bool enough_days(int &mid,int m,int &k,vector<int>&max_in_interval){
        for(int i = 0;i<max_in_interval.size();i++){
            if(max_in_interval[i] <= mid){m--;i+=k-1;}
            if(m==0)return true;
        }
        return m==0;
    }
    int minDays(vector<int>& b, int m, int k) {
        if(1LL *m*k > b.size())return -1;
        int n = b.size();
        int lo = 1,hi = b[0];
        vector<int>max_in_interval;
        for(int i = 0;i+k-1<n;i++){
            int x = b[i];
            for(int j = i;j<=i+k-1;j++){
                hi = max(hi,b[j]);
                x = max(x,b[j]);
            }
            max_in_interval.push_back(x);
        }
        int ans = hi;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(enough_days(mid,m,k,max_in_interval)){ans = min(ans,mid);hi = mid-1;}
            else lo = mid+1;
        }
        return ans;
    }
};