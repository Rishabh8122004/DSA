class Solution {
public:
    bool can_be_distributed(int x,vector<int>& candies, long long k){
        long long int c = 0;
        for(int i = 0;i<candies.size();i++){
            if(candies[i]>=x){
                c+=(candies[i]/x);
            }
        }
        return c>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int m = 0,n = candies.size(),ans = 0;
        for(int i = 0;i<n;i++){
            if(m<candies[i])m = candies[i];
        }
        int lo = 1,hi = m;
        while(lo<=hi){
            int mid = (lo+(hi-lo)/2);
            if(can_be_distributed(mid,candies,k)){ans = mid;lo= mid+1;}
            else hi = mid-1;
        }
        return ans;
    }
};