class Solution {
public:
    vector<string> braceExpansionII(string e) {
        int n = e.size();
        vector<string> merge;
        vector<string> concatenate;
        // STEP 1: Find whether ROOT is OR
        int depth = 0;
        int start = 0;
        for (int i = 0; i < n; i++) {

            if (e[i] == '{') {
                depth++;
            }
            else if (e[i] == '}') {
                depth--;
            }
            else if (e[i] == ',' && depth == 0) {

                // Root is OR
                merge.push_back(e.substr(start, i - start));

                start = i + 1;
            }
        }
        // If we found a root-level comma,
        // complete the last OR child.
        if (!merge.empty()) {

            merge.push_back(e.substr(start));

        }
        // STEP 2: If no OR, find root-level AND pieces
        else {
            int i = 0;
            while (i < n) {
                // A brace expression
                if (e[i] == '{') {
                    int j = i;
                    int depth = 1;
                    while (j + 1 < n && depth > 0) {
                        j++;
                        if (e[j] == '{')
                            depth++;
                        else if (e[j] == '}')
                            depth--;
                    }
                    // Remove outer { }
                    concatenate.push_back(e.substr(i + 1, j - i - 1));
                    i = j + 1;
                }
                // A normal lowercase string
                else {
                    int j = i;
                    while (j < n && e[j] != '{') {
                        j++;
                    }
                    concatenate.push_back(
                        e.substr(i, j - i)
                    );

                    i = j;
                }
            }
        }
        // STEP 3: Evaluate ROOT = OR
        vector<string> ans;
        if (!merge.empty()) {
            unordered_set<string> st;
            for (auto& s : merge) {
                vector<string> temp =
                    braceExpansionII(s);

                for (auto& p : temp) {
                    st.insert(p);
                }
            }
            for (auto& p : st) {
                ans.push_back(p);
            }
        }
        // STEP 4: Evaluate ROOT = AND
        else {
            unordered_set<string> st;
            // Literal expression
            if (concatenate.size() == 1 &&
                concatenate[0] == e) {
                return {e};
            }
            vector<string> first =  braceExpansionII(concatenate[0]);
            for (auto& p : first) {
                st.insert(p);
            }
            for (int i = 1; i < concatenate.size(); i++) {
                vector<string> temp = braceExpansionII(concatenate[i]);
                unordered_set<string> next;
                for (auto& p : st) {
                    for (auto& q : temp) {
                        next.insert(p + q);
                    }
                }
                st = next;
            }
            for (auto& p : st) {
                ans.push_back(p);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};