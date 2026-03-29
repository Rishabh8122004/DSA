class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        vector<int>even(26,0),odd(26,0);
        for(int i = 0;i<n;i++){
            if(i%2 == 0){
                even[s1[i]-97]++;
                even[s2[i]-97]--;
            }
            else{
                odd[s1[i]-97]++;
                odd[s2[i]-97]--;
            }
        }
        for(int i = 0;i<26;i++){
            if(even[i] || odd[i])return false;
        }
        return true;
    }
};