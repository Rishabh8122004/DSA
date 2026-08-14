class Solution {
public:
    int maximumLengthSubstring(string s) {
        int k = 2;
        unordered_map<char,int>mp;
        bool f = false;
        int i = 0,j = 0,ans = 0;
        int n = s.size();
        while(j<n){
            if(i>j)j = i;
            mp[s[j]]++;
            if(mp[s[j]]>k){
                f = true;
            }
            if(f){
                while(i<=j && mp[s[j]]>k){
                    mp[s[i]]--;
                    i++;
                }
                f = false;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};