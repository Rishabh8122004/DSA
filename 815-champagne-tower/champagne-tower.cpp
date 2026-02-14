class Solution {
public:
    double champagneTower(int poured, int qr, int qg) {
        int i = 0,j = 0;
        vector<double>curr(i+1,poured);
        while(i<=qr){
            j = 0;
            vector<double>next(i+2);
            while(j<=qg && j<curr.size()){
                if(i == qr && j == qg){
                    return (curr[j]>=1?1:curr[j]);
                }
                double x = curr[j]>1?curr[j]-1:0;
                if(x>0){
                x/=2;
                next[j]+=x;
                next[j+1]+=x;
                }
                j++;
            }
            curr = next;
            i++;
        }
        return 0;
    }
};