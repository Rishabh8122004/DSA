class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(ranges.begin(),ranges.end());
        for(int i = 0;i<ranges.size();i++){
            if(left>right)return true;
            if(left>=ranges[i][0] && left <= ranges[i][1]) left+=(ranges[i][1]-left+1);
        }
        return left>right;
    }
};