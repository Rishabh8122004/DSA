class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        vector<int>v(256);
        int i = 0,j = 0;
        while(j<n){
            v[(int)s[j]]++;
            if(v[(int)s[j]]>1){
                while(v[(int)s[j]]!=1){v[(int)s[i]]--;i++;}
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};