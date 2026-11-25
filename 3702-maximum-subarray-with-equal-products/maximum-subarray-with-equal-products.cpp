class Solution {
public:
    int gcd(int a,int b){
        int c = min(a,b);
        a = max(a,b);
        b = c;
        while(a%b != 0){
            c = a%b;
            a = b;
            b = c;
        }
        return b;
    }
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int len = n;
        while(len>=2){  
            int j = len;
            while(j<=n){
            long long int p = nums[j-len]*nums[j-len+1],g = gcd(nums[j-len],nums[j-len+1]),l = (nums[j-len]*nums[j-len+1])/g;
            for(int i = j-len+2;i<j;i++){
                p = (p*nums[i])%10000000000000000;
                g = (gcd(g,nums[i]));
                l = ((l*nums[i])/gcd(l,nums[i]));
            }
            if(p == (l*g)%10000000000000000) return len;
                j++;
            }
            len--;
        }
        return 2;
    }
};