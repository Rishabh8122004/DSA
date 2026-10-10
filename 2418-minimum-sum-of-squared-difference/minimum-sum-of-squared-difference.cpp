class Solution {
public:
    long long minSumSquareDiff(vector<int>& n1, vector<int>& n2, int k1, int k2) {
        long long k = k1+k2,n = n1.size();
        vector<long long>diff(1e5+5,0);
        for(int i = 0;i<n;i++){
            diff[abs(n1[i]-n2[i])]++;
        }
        for(int i = 1e5+1;i>=1;i--){
            if(diff[i] == 0)continue;
            long long cnt = min(diff[i],k);
            diff[i-1]+=cnt;
            diff[i]-=cnt;
            k-=cnt;
        }
        long long ans = 0;
        for(int i = 0;i<diff.size();i++){
            ans += (diff[i]*i*i);
        }
        return ans;
    }
};