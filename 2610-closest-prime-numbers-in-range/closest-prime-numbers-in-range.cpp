class Solution {
public:
    bool isprime(int n){
        if(n == 1)return false;
        int x = sqrt(n);
        for(int i = 2;i<=x;i++){
            if(n%i == 0)return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int>v;
        for(int i = left;i<=right;i++){
            if(isprime(i))v.push_back(i);
        }
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