class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int ans = 0;
        int n = original.size();
        int j = bounds[n-1][0],k = bounds[n-1][1],l,m;
        bool flag = true;
        for(int i = n-2;i>=0;i--){
            int d = original[i+1]-original[i];
            l = bounds[i][0];m = bounds[i][1];
            if(j-l != d){
                if(j-l<d)j+=(d-j+l);
                if(j-l>d)l+=(j-l-d);
            }
            if(k-m !=d){
                if(k-m>d)k-=(k-m-d);
                if(k-m<d)m-=(d-k+m);
            }
            if(j-l != d || k-m !=d)return 0;
            if(k<j || m<l)return 0;
            j = l;k = m;
        }
        return m-l+1;
    }
};