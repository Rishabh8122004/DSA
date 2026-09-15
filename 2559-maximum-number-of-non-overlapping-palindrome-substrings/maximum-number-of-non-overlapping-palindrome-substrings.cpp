class Solution {
public:
    int ans = 0;
    bool is_palindrome(string &s,int l,int r){
        while(l<=r){
            if(s[l] != s[r])return false;
            l++;r--;
        }
        return true;
    }
    void solve(string& s, int& i, int& k) {

    // Search by ending index first.
    // Therefore, the first palindrome found ends as early as possible.
    for (int r = i + k - 1; r < s.size(); r++) {

        // Try every possible starting index for this ending position.
        for (int l = i; l <= r-k+1; l++) {

            if (is_palindrome(s, l, r)) {

                cout << s.substr(l, r-l+1)
                     << "  " << l << "-" << r << endl;

                i = r + 1;
                ans++;

                return;
            }
        }
    }

    i = s.size();
}
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if (k == 1)
            return n;
        int i = 0;
        while (i < n) {
            solve(s, i, k);
        }
        return ans;
    }
};