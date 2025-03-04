class Solution {
public:
    long long calculateScore(string s) {
        int n = s.size();
        long long int ans = 0;
        vector<vector<int>>v;
        for(int i = 0;i<26;i++)v.push_back({-1}); // SETTING ALL THE 26 VECTORS WITH -1 AS THEIR BEGGINER ELEMENT TO AVOID SOME ISSUES
        bool flag = true; // FLAG TO TELL US THAT CURRENT ELEMENT IS OKAY TO PUSH BACK OR NOT ?
        for(int i = 1;i<n;i++){
            if(flag) v[s[i-1]-'a'].push_back(i-1); // IF PREVIOUS ELEMENT IS'NT USED EARLIER AS A MIRROR ELEMENT THEN PUSH_BACK IT .
            flag = true;
            if(v['z'-s[i]].size()>1){//IS ANY MIRROR ELEMENT AVAILABLE TILL CURRENT INDEX ?
                ans+=(i-v['z'-s[i]][v['z'-s[i]].size()-1]); // IF YES, THEN WE GOTTA UPDATE THE ANSWER
                v['z'-s[i]].pop_back(); // REMOVING THE USED MIRROR ELEMENT'S INDEX
                flag = false;/// MARKING THE CURRENT ELEMENT AS MARKED TO AVOID USING IT IN THE NEXT STEP.
            }
        }
        return ans;
    }
};