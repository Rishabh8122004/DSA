class Solution {
public:
    int findPoisonedDuration(vector<int>& ts, int d) {
        int n = ts.size();
        int ans = 0;
        int seconds = 0;
        int poisioned_till = -1;
        for(int i = 0;i<n;i++){
            if(ts[i]>poisioned_till){
                ans+=seconds;
                seconds = 0;
            }
            else{
                seconds-=(poisioned_till-ts[i]+1);
            }
            poisioned_till = ts[i]+d-1;
            seconds+=((ts[i]+d)-ts[i]);
        }
        ans+=seconds;
        return ans;
    }
};