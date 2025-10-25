class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int i = 1,j = 1;
        while(n){
            for(int k = 1;k<=7 && n>0;k++){
                ans+=i;
                n--;
                i++;
            }
            i = j+1;
            j++;
        }
        return ans;
    }
};