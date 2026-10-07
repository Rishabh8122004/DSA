class Solution {
public:
    bool is_valid(string& x) {
        int noo = 0;

        for (int i = 0; i < x.size(); i++) {
            if (x[i] == '(')
                noo++;
            else if (x[i] == ')') {
                if (noo == 0)
                    return false;
                noo--;
            }
        }

        return noo == 0;
    }

    unordered_set<string> ans;
    int m = 0;

    void solve(string& s, int i, string& x) {
        if (i == s.size()) {
            if (is_valid(x)) {
                if (x.size() > m) {
                    m = x.size();
                    ans.clear(); // empty the answer because we have find the minimum deletion till now.
                    ans.insert(x);
                } else if (x.size() == m) {
                    ans.insert(x);
                }
            }
            return;
        }

        // Non-parenthesis: must keep it
        if (s[i] != '(' && s[i] != ')') {
            x.push_back(s[i]);
            solve(s, i + 1, x);
            x.pop_back();
        } else {
            // Keep this parenthesis
            x.push_back(s[i]);
            solve(s, i + 1, x);
            x.pop_back();

            // Remove this parenthesis
            solve(s, i + 1, x);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        if (is_valid(s))
            return {s};

        ans.clear();
        m = 0;

        string x;
        x.reserve(s.size()); // fix the maximum size of x

        solve(s, 0, x);

        vector<string> v;

        for (auto& p : ans)
            v.push_back(p);

        return v;
    }
};