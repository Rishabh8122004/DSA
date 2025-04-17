class Solution {
public:
    int countPairs(vector<int>& nums, int p) {
        int n = nums.size();
        vector<vector<pair<int,int>>>v;
        v.push_back({{nums[0],0}});
        for(int i = 1;i<n;i++){
            bool f = false;
            for(int j = 0;j<v.size();j++)
            {
                if(v[j][0].first == nums[i]){v[j].push_back({nums[i],i});f = true;break;}
            }
            if(!f){
                v.push_back({{nums[i],i}});
            }
        }
        int ans = 0;
        for(int i = 0;i<v.size();i++){
            for(int j = 0;j<v[i].size();j++){
                for(int k = j+1;k<v[i].size();k++){
                    if((v[i][j].second*v[i][k].second)%p ==  0)ans++;
                }
            }
        }
        return ans;
    }
};