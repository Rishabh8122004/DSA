class Solution {
public:
    int rotate(int x){
        if(x == 2)return 5;
        if(x == 5)return 2;
        if(x == 6)return 9;
        if(x == 9)return 6;
        return x;
    }
    bool is_good(int x){
        int y = x;
        vector<int>v;
        while(y){
            v.push_back(y%10);
            y/=10;
        }
        y = 0;
        for(int i = v.size()-1;i>=0;i--){
            if(v[i] == 3 || v[i] == 4 || v[i] == 7)return false;
            y *= 10;
            y += rotate(v[i]);
        }
        return y != x;
    }
    int rotatedDigits(int n) {
        int ans = 0;
        while(n){
            if(is_good(n))ans++;
            n--;
        }
        return ans;
    }
};