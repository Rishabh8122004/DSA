class Solution {
public:
    bool is_palindrome(string w) {
        int i = 0, j = w.size() - 1;
        while (i < j) {
            if (w[i++] != w[j--]) {
                return false;
            }
        }
        return true;
    }
    int maximumNumberOfStringPairs(vector<string>& w) {
        int n = w.size();
        unordered_set<string> s;
        int pairs = 0;
        for (int i = 0; i < n; i++) {
            if (is_palindrome(w[i]))continue;
            string str = w[i];
            reverse(w[i].begin(),w[i].end());
            if(s.find(w[i]) != s.end()){ // reverse already exist
            pairs++;
            s.erase(w[i]);
            }
            else s.insert(str);
        }
        return pairs;
    }
};