class Solution {
public:
    string reverseVowels(string s) {
        vector<int> idx;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'I' || s[i] == 'i' || s[i] == 'E' || s[i] == 'e' ||
                s[i] == 'O' || s[i] == 'o' || s[i] == 'A' || s[i] == 'a' ||
                s[i] == 'U' || s[i] == 'u') {
                idx.push_back(i);
            }
        }
        for (int i = 0; i < idx.size()/2; i++) {
            swap(s[idx[i]],s[idx[idx.size()-i-1]]);
        }
        return s;
    }
};