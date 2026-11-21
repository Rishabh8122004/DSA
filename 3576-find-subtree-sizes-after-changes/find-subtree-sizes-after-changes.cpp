class Solution {
public:
    vector<stack<int>> last_seen{26};
    void dfs(int i, vector<vector<int>>& child, string& s, vector<int>& p) {
        int c = s[i]-'a';
        if (!last_seen[c].empty()) {
            p[i] = last_seen[c].top();
        }
        last_seen[c].push(i);
        for (int j = 0; j < child[i].size(); j++) {
            dfs(child[i][j], child, s, p);
        }
        last_seen[c].pop();
        return;
    }
    int size(int i, vector<int>& ans, vector<vector<int>>& child) {
        int total = 1;
        for(int j = 0;j<child[i].size();j++){
            total += size(child[i][j],ans,child);
        }
        return ans[i] = total;
    }
    vector<int> findSubtreeSizes(vector<int>& p, string s) {
        int n = p.size();
        vector<vector<int>> child(n);
        for (int i = 1; i < n; i++) {
            child[p[i]].push_back(i);
        }
        dfs(0, child, s, p);
        for(int i = 0;i<n;i++){
            child[i] = {};
        }
        for (int i = 1; i < n; i++) {
            child[p[i]].push_back(i);
        }
        vector<int> ans(n, 0);
        size(0, ans, child);
        return ans;
    }
};