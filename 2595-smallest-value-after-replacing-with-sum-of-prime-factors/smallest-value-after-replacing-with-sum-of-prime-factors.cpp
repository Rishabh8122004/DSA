class Solution {
public:
    bool isprime(int x){
        if(x == 1)return false;
        int a = sqrt(x);
        for(int i = 2;i<=a;i++){
            if(x%i == 0)return false;
        }
        return true;
    }
    int smallestValue(int n) {
        if(isprime(n))return n;
        int ans;
        int sum = 0;
        vector<int> pfactor; // prime factors
        for(int i = 2;i<sqrt(n);i++){
            if((n%i == 0) && (isprime(i))){
                int m = n;
                while(m%i == 0){
                    sum+=i;
                    m/=i;
                }
            }
        }
        for(int i = sqrt(n);i>1;i--){
            if((n%(n/i) == 0) && (isprime(n/i))){
                int m = n;
                while(m%(n/i) == 0){
                    sum+=(n/i);
                    m/=(n/i);
                }
            }
        }
        if(sum == n) return n;
        return smallestValue(sum);
    }
};