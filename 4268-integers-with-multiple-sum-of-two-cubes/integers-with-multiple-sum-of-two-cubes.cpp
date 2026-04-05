class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        map<int,int>mp;
        for(int i = 1;i*i*i<=n/2;i++){

            for(int j = i;j*j*j<=(n-(i*i*i));j++){
                int sum = i*i*i + j*j*j;
                mp[sum]++;
            }
        }
        vector<int>ans;
        for(auto x :mp){
            if(x.second >=2)ans.push_back(x.first);
        }
        return ans;
    }
};