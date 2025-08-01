class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > v;
        for(int i = 0;i<numRows;i++)
        {
            vector<int> a(i+1);
            v.push_back(a);
            for(int j = 0;j<=i;j++)
            {
                if(j==0 || j==i)
                {
                    v[i][j] = 1;
                }
                else{ v[i][j] = v[i-1][j]+v[i-1][j-1];}
            }
        }
         return v;
    }
};