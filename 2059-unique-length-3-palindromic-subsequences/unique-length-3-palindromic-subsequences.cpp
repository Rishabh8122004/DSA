class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int c = 0;
        vector<bool> v(26,false); // to make sure we don't consider same subsequence again in the answer
        // our intuition is to find the right most element which is simmilar to the current element 
        for(int i = 0;i+2<n;i++){ // iterate forn i = 0 to n-1-2
            if(v[s[i]-'a'] == true) continue; // if taken already? then contnue;
            for(int j = n-1;j>=i+2;j--){  // iterate from n-1 to i+2, so that we made sure that the index is right most
                if(s[i] == s[j]){ // if we found any ? 
                    v[s[i]-'a'] = true; // marking this subsequence as taken already for further calculations 
                    vector<bool>p(26,false);// for counting the number of distinct elements b/w s[i] & s[j] so that we got diffrent existing possiblities using the current indices
                    for(int k = i+1;k<j;k++){ 
                        c+=(!p[s[k]-'a']?1:0); // if found a diffrent character , increment the answer
                        p[s[k]-'a'] = true; // marking the current element as founded or existed
                    }
                    break;
                }
            }
        }
        return c;
    }
};