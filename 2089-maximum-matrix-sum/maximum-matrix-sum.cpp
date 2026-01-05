class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& m) {
        int n = m.size();
        int min = INT_MAX;
        bool neg = false;
        long long sum = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                sum += abs(m[i][j]);
                if(m[i][j] < 0){
                    neg = !neg;
                    if(-1*m[i][j] < min){
                        min = abs(m[i][j]);
                    }
                }
                else{
                    if(m[i][j] < min){
                        min = m[i][j];
                    }
                }
            }
        }
        return (neg?sum-2*min:sum);
    }
};