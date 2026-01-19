class Solution {
public:
    int get_minsum(int &k,vector<vector<int>>&r,int &threshold){
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
        int k = 1;
        while(k <= min(m,n)){
            if(get_minsum(k,r,threshold) > threshold)return k-1;
            k++;
        }
        return k-1;
    }
};