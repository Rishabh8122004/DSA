class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int s = 0;
        int k = x;
        while(k){
            s+=k%10;
            k/=10;
        }
        return (x%s == 0?s:-1);
    }
};