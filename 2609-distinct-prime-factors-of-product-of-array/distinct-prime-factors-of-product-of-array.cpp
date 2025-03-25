class Solution {
public:
    bool isprime(int x) {
        if (x == 1)
            return 0;
        int a = sqrt(x);
        for (int i = 2; i <= a; i++) {
            if (x % i == 0)
                return 0;
        }
        return 1;
    }
    void factorisprime(int x, vector<int>& prime) {
        vector<int> v;
        int a = sqrt(x);
        for (int i = 2; i <= a; i++) {
            if (x % i == 0) {
                v.push_back(i);
                v.push_back(x / i);
            }
        }
        for (int i = 0; i < v.size(); i++) {
            if (isprime(v[i])) {
                bool flag = true;
                for (int j = 0; j < prime.size(); j++) {
                    if (v[i] == prime[j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    prime.push_back(v[i]);
            }
        }
        return;
    }
    int distinctPrimeFactors(vector<int>& nums) {
        vector<int> prime;
        for (int i = 0; i < nums.size(); i++) {
            if (isprime(nums[i])) {
                bool flag = true;
                for (int j = 0; j < prime.size(); j++) {
                    if (nums[i] == prime[j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    prime.push_back(nums[i]);
            } else {
                factorisprime(nums[i], prime);
            }
        }
        return prime.size();
    }
};