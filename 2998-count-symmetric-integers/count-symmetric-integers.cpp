class Solution {
public:
    bool issymmetric(int x){
        vector<int>v;
        while(x){
            v.push_back(x%10);
            x/=10;
        }
        int s1 = 0;
        for(int i = 0;i<v.size();i++){
            if(i<v.size()/2){s1+=v[i];}
            else s1-=v[i];
        }
        return s1 == 0;
    }
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low;i<=high;i++){
            if(i>=1 && i<10){i = 9;continue;} 
            else if(i>=100 && i<1000){i = 999;continue;} 
            if(issymmetric(i))ans++;
        }
        return ans;
    }
};