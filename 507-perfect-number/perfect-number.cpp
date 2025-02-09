class Solution {
public:
    bool checkPerfectNumber(int num) {
        int a = sqrt(num);
        int sum = 1;
        for(int i = 2;i<=a;i++){
            if(num%i == 0){
                sum+=i;
                sum+=(num/i);
            }
        }
        if(sum == num && num>1)return true;
        return false;
    }
};