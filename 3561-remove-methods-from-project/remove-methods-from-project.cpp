class Solution {
public:
    class node {
    public:
        int val;
        vector<node*> in, out;
        node(int x) { this->val = x; }
    };
    void dfs(int k, unordered_map<int, node*>& mp, vector<int>& vis) {
        if (vis[k] == 1)
            return;
        vis[k] = 1;
        for (auto p : mp[k]->out) {
            dfs(p->val, mp, vis);
        }
        return;
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& i) {
        unordered_map<int, node*> mp;
        for (int i = 0; i < n; i++)
            mp[i] = new node(i);
        node *a, *b;
        for (auto p : i) {
            a = mp[p[0]];
            b = mp[p[1]];
            a->out.push_back(b);
            b->in.push_back(a);
        }
        vector<int> vis(n);
        dfs(k, mp, vis);
        bool f = true;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 1) {
                for (auto p : mp[i]->in) {
                    if (vis[p->val] == 0) {
                        f = false; // some not suspicious is invoking the
                                   // suspicious , so can not remove anyone
                        break;
                    }
                }
            }
            if (!f)
                break;
        }
        if (!f) {
            for (int i = 0; i < n; i++) {
                vis[i] = i;
            }
            return vis; // nobody is removed
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0)
                ans.push_back(i);
        }
        return ans;
    }
};