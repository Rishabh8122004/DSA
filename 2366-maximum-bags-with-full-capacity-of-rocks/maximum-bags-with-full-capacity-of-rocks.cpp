class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int>diff;
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(rocks[i] == capacity[i])ans++;
            else if(rocks[i]<capacity[i])diff.push_back(capacity[i]-rocks[i]);
        }
        sort(diff.begin(),diff.end());
        for(int i = 0;i<diff.size();i++){
            if(additionalRocks<diff[i])break;
            else {additionalRocks-=diff[i];
            ans++;}
        }
        return ans;
    }
};