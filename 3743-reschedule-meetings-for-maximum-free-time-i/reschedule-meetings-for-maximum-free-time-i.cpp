class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& st, vector<int>& et) {
        int n = st.size();
        if(et[n-1]<eventTime){
            st.push_back(eventTime);
            et.push_back(eventTime);
            n++;
        }
        int maxbreaks = 0;
        int currbreaks = 0;
        for(int i = 0;i<=k;i++){
            if(i == n){
                currbreaks+=(eventTime-et[i-1]); // our time line - last time we attended  meeting
                break;
            }
            currbreaks+=(i == 0?(st[i]):(st[i]-et[i-1]));
        }
        maxbreaks = max(maxbreaks,currbreaks);
        int i = 0,j = k+1;
        while(j<n){
            currbreaks+=(st[j]-et[j-1]);
            currbreaks-=(i == 0?(st[i]):(st[i]-et[i-1]));
            maxbreaks = max(maxbreaks,currbreaks);
            j++;i++;
        }
        return maxbreaks;
    }
};