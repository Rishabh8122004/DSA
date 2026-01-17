class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr) {
        int n = bl.size();
        int l,b,ans = 0;;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(j == i)continue;
                l = min(tr[i][1],tr[j][1])-max(bl[j][1],bl[i][1]);
                b = min(tr[i][0],tr[j][0])-max(bl[j][0],bl[i][0]);
                if(l<0 || b<0)continue; 
                ans = max(ans,min(l,b));
            }
        }
        return 1LL*ans*ans;
    }
};