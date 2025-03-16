class Solution {
public:
    bool isvalid(long long x,vector<int>& ranks, int cars){
        for(int i = 0;i<ranks.size();i++){
            cars -= (long long)sqrt(x / (double)ranks[i]);
            if(cars<=0)return true;
        }
        return cars <= 0;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long ans = 0;
        int m = INT_MAX;
        for(int i = 0;i<ranks.size();i++){m = min(m,ranks[i]);}
        long long lo = 1,hi = (long long)(m*(long long)(cars*(long long)cars));
        while(lo<=hi){
            long long mid = lo+(hi-lo)/2;
            if(isvalid(mid,ranks,cars)){ans = mid;hi = mid-1;}
            else lo = mid+1;
        }
        return ans;
    }
};