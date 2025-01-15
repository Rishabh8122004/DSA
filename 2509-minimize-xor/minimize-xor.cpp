class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int ans = 0;
        bitset<32> a(num1);
        bitset<32> b(num2);
        int count = 0;
        for(int i = 0;i<32;i++){
            if(b[i] == 1)count++;
            if(a[i] == 1)count--;
        }
        if(count<0){
            for(int i = 0;i<32;i++){if(a[i] == 1 && count<0){a[i] = 0;count++;}
            if(count == 0)break;
            }
        }
        for(int i = 0;i<32;i++){
            if(a[i] != 1 && count>0){a[i] = 1;count--;}
            if(count == 0) break;
        }
        long int m = 1;
        for(int i = 0;i<32;i++){
            ans+=(a[i]==1?m:0);
            m*=2;
        }
        return ans;
    }
};