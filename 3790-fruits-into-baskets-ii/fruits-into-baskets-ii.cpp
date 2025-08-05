class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool>v(n,false);
        int ans = 0;
        for(int i = 0;i<n;i++){
            bool flag = false;
            for(int j = 0;j<n;j++){
                if(baskets[j]>=fruits[i] && !v[j]){flag = true;v[j] = true;break;}
            }
            if(!flag)ans++;
        }
        return ans;
    }
};