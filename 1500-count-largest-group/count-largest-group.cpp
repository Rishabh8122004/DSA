class Solution {
public:
    int sum(int n){
        int sum = 0;
        while(n){sum+=n%10;n/=10;}
        return sum;
    }
    int countLargestGroup(int n) {
        vector<int>v(36+1);
        int i = 1;
        while(i<=n){
            v[sum(i)]++;
            i++;
        }
        int ans = 37,largest = 0;
        for(int i = 0;i<v.size();i++){
            largest = max(largest,v[i]);
        }
        for(int i = 0;i<v.size();i++){
           if(v[i]<largest)ans--;
        }
        return ans;
    }
};