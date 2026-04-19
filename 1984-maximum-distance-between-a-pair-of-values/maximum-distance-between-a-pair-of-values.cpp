class Solution {
public:
    int maxDistance(vector<int>& n1, vector<int>& n2) {
        int ans = 0;
        int i = 0,j = 0;
        int n = min(n1.size(),n2.size());
        while(i<n){
            if(j<i)j = i;
            while(j+1<n2.size() && n2[j+1]>=n1[i])j++;
            if(j == n2.size()-1 && n2[j]<n1[i])break;
            ans = max(ans,abs(j-i));
            i++;
        }
        return ans;
    }
};