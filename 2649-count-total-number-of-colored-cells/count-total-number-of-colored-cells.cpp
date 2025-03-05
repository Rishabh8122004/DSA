class Solution {
public:
    long long solve(int n,long long cn,long long pn){
        if(n == 0)return cn;
        return solve(n-1,((2*cn)-pn+4),cn);
    }
    long long coloredCells(int n) {
        if(n == 1)return 1;
        return solve(n-2,5,1);
    }
};