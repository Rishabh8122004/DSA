class Solution {
public:
    int mirrorDistance(int n) {
        int x = 0,y = n;
        while(y){
            x *= 10;
            x += (y%10);
            y/=10;
        }
        return abs(n-x);
    }
};