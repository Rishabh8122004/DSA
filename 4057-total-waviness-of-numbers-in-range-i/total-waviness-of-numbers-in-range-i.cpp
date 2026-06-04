class Solution {
public:
    int totalWaviness(int n1, int n2) {
        int ans = 0;
        if(n2<=100)return 0;
        int x;
        while(n1<=n2){
            x = n1;
            n1++;
            if(x<100)continue;
            int next = x%10,prev,curr;
            x/=10;
            while(x>9){
                prev = ((x/10)%10);
                curr = (x%10);
                if(curr>prev && curr>next)ans++;
                if(curr<prev && curr<next)ans++;
                next = curr;
                x/=10;
            }
        }
        return ans;
    }
};