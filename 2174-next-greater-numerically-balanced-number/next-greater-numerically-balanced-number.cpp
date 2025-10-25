class Solution {
public:
    bool isbalanced(int n){
        vector<int>v(10);
        while(n){
            v[n%10]++;
            n/=10;
        }
        for(int i = 1;i<10;i++){
            if(v[i] != i && v[i] != 0)return false;
        }
        return v[0] == 0;
    }
    int nextBeautifulNumber(int n) {
        for(n;n>=0;n++){
            if(isbalanced(n+1))return n+1;
        }
        return 0;
    }
};