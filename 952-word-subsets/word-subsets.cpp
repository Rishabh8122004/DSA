class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        int n = words1.size();
        vector<int> mfreq(26,0);
        for(int i = 0;i<words2.size();i++){
            vector<int> freq(26,0);
            for(int j = 0;j<words2[i].size();j++){
                freq[words2[i][j]-'a']++;
            }
            for(int j = 0;j<26;j++){
                mfreq[j] = max(mfreq[j],freq[j]);
            }
        }
        for(int i = 0;i<words1.size();i++){
            vector<int> freq(26,0);
            for(int j = 0;j<words1[i].size();j++){
                freq[words1[i][j]-'a']++;
            }
            bool valid = true;
            for(int i = 0;i<26;i++){
                if(freq[i]<mfreq[i]){valid = false;break;}
            }
            if(valid) ans.push_back(words1[i]);
        }
        return ans;
    }
};