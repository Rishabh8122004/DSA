class Solution {
public:
    long solve(long a,long b){
        //cout<<a<<"  "<<b<<endl;
        if(a<b || a == 0)return 0;
        int x = 0;
        while((long)((long)b<<(x+1)) <= a ){
            x++;
        } 
        return (pow(2,x))+solve(a-(b<<x) , b);
    }
    int divide(int a, int b) {
        if(a == b)return 1;
        if(b == 1)return a;
        if(a == -2147483648 && b<0)a++;
        if(b == -1){return -a;}
        long ans = solve(abs((long) a),abs((long) b));
        if(ans > 2147483648)ans = 2147483648;
        return ((a<0 == b<0)?ans:(-ans));
    }
};