class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int ans = 0;
        sort(meetings.begin(),meetings.end());
        ans+=meetings[0][0]-1;
        int m = meetings[0][1];
        for(int i = 1;i<meetings.size();i++){
            if(meetings[i][0]>m){ans+=(meetings[i][0]-m-1);}
            m = max(m,meetings[i][1]);
        }
        ans+=(days-m);
        return ans;
    }
};