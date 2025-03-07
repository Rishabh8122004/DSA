class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> sieve(right + 1, true);
        sieve[0] = sieve[1] = false;       
        for (int i = 2; i * i <= right; ++i) {
            if (sieve[i]) {
                for (int j = i * i; j <= right; j += i) {
                    sieve[j] = false;
                }
            }
        }
        vector<int>v;
        for(int i = left;i<=right;i++){if(sieve[i])v.push_back(i);}
        int n1 = -1,n2 = -1,dif = INT_MAX;
        for(int i = 1;i<v.size();i++){
            if(v[i]-v[i-1]<dif){
                dif = v[i]-v[i-1];
                n1 = v[i-1];n2 = v[i];
            }
        }
        return {n1,n2};
    }
};