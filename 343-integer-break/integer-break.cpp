class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return n-1;
        int threes = n/3;
        int rem = n%3;
        if(rem == 1){
            rem = 4;
            threes--;
        }
        else if(rem == 0)rem = 1;
        return (pow(3,threes)) * rem;
    }
};