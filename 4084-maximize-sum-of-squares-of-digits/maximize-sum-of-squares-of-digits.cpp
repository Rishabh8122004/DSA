class Solution {
public:
    string maxSumOfSquares(int n, int sum) {
        string ans = "";
        for(int  i = 0;i<n;i++){
            for(int j = 9;j>=0;j--){
                if((i == 0 && j == 0) || (i == n-1 && j < sum))return "";
                if(j <= sum){ans.push_back('0'+j);sum-=j;break;}
            }
        }
        return ans;
    }
};