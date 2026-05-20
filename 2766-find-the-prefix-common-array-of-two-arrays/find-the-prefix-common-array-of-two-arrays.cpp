class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int i = 0;
        int n = a.size(),c=0;
        vector<int>freq(n+1);
        while (i < n) {
            freq[a[i]]++;
            if(freq[a[i]] == 2)c++;
            freq[b[i]]++;
            if(freq[b[i]] == 2)c++;
            a[i] = c;
            i++;
        }
        return a;
    }
};