class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0;
        vector<int>lower(27,0),upper(27,0);
        for(int i = 0;i<word.size();i++){
            if(word[i]>='a' && word[i]<='z')lower[word[i]-'a']++;
            else upper[word[i]-'A']++;
        }
        for(int i = 0;i<27;i++){
            if(lower[i]>0 && upper[i]>0)ans++;
        }
        return ans;
    }
};