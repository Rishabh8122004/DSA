class Solution {
public:
    int get_minsum(int k,vector<vector<int>>&r,int &threshold){
        int sum = INT_MAX,a,temp = 0;
        for(int i = 0;i+k-1<r.size();i++){
            for(int j = 0;j+k-1<r[0].size();j++){
                temp = 0;
                a = i;
                while(a<=i+k-1){
                    temp += (r[a][j+k-1] - (j == 0?0:r[a][j-1]));
                    a++;
                }
                sum = min(sum,temp);
                if(sum<=threshold)return sum;
            }
        }
        return sum;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(),m = mat[0].size();
        vector<vector<int>>r = mat;
        for(int i = 0;i<n;i++){
            for(int j = 1;j<m;j++){
                r[i][j] += r[i][j-1];
            }
        }
        int lo = 1,hi = min(m,n);
        int ans = 0;
        while(lo<=hi){
            int mid = (lo+(hi-lo)/2);
            if(get_minsum(mid,r,threshold)<=threshold){ans = max(ans,mid);lo = mid+1;}
            else hi = mid-1;
        }
        return ans;
    }
};