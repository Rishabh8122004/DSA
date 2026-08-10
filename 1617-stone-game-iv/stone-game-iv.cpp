class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int>v(n+1,0);
        for(int i = 1;i<=n;i++){
            int j = 1;
            while(i-(j*j)>=0){
                if(v[i-(j*j)] == 0){
                    v[i] = 1;
                    break;
                }
                j++;
            }
        }
        return v[n];
    }
};