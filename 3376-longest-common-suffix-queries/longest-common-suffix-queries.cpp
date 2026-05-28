class Solution {
public:

    vector<vector<int>> trie;
    vector<int> idx;

    void insert_string(int root, int i, vector<string>& c) {

        string s = c[i];

        for (int j = s.size() - 1; j >= 0; j--) {

            char ch = s[j];

            if (trie[root][ch - 'a'] == -1) {

                trie[root][ch - 'a'] = trie.size();

                trie.push_back(vector<int>(26, -1));

                idx.push_back(i);
            }

            int next = trie[root][ch - 'a'];

            if (c[idx[next]].size() > s.size()) {
                idx[next] = i;
            }

            root = next;
        }
    }

    int search(string s, int root) {

        int ans = idx[root];

        for (int i = s.size() - 1; i >= 0; i--) {

            char ch = s[i];

            if (trie[root][ch - 'a'] == -1)
                return ans;

            root = trie[root][ch - 'a'];

            ans = idx[root];
        }

        return ans;
    }

    vector<int> stringIndices(vector<string>& c, vector<string>& q) {

        int m = c.size(), n = q.size();

        trie.push_back(vector<int>(26, -1));
        idx.push_back(0);

        vector<int> ans(n);

        for (int i = 0; i < m; i++) {

            if (c[idx[0]].size() > c[i].size()) {
                idx[0] = i;
            }

            insert_string(0, i, c);
        }

        for (int i = 0; i < n; i++) {
            ans[i] = search(q[i], 0);
        }

        return ans;
    }
};