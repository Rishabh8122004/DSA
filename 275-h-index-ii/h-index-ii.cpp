class Solution {
public:
    int hIndex(vector<int>& c) {
        for(int i = 0;i<c.size();i++){
            if(c[i] >= c.size()-i)return c.size()-i;
        }
        return c[0] == 0?0:1;
    }
};