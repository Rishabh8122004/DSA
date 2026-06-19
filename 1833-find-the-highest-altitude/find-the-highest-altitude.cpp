class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int x = 0;
        for(int i = 0;i<gain.size();i++){
            x+=gain[i];
            if(ans< x)ans = x;
        }
        return ans;
    }
};