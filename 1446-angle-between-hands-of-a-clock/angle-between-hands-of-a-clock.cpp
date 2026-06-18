class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans = minutes*6;
        ans -= ((hour%12)*(360/12));
        ans -= (minutes*0.5);
        ans = abs(ans);
        return min(360-ans,ans);
    }
};