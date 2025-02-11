class Solution {
public:
    bool isprime(int x){
        if(x == 1)return 0;
        for(int i = 2;i<=sqrt(x);i++){
            if(x%i == 0)return 0;
        }
        return 1;
    }
    int minSteps(int n) {
        if(n == 1) return 0;
        if(isprime(n))return n;
        int steps = 0;
        // we have to find the minimum prime factor of the number n 
        int minsum = n;
        for(int i = 2;i<=sqrt(n);i++){
            if(n%i == 0){
                if(minsum>(i+(n/i))){minsum = i+minSteps(n/i);}
            }
        }
        return minsum;
    }
};