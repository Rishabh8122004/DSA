class Solution {
public:
    int maxProduct(int n) {
        vector<int>v;
        while(n){
            v.push_back(n%10);
            n/=10;
        }
        n = v.size();
        int m = 0;
        for(int i = 0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                if(m < (v[i]*v[j]))m = v[i]*v[j];
            }
        }
        return m;
    }
};