class Solution {
public:
    class node {
        public:
        int val;
        node(int x) { this->val = x; }
    };
    int ans = 1e5,n;
    int vis[100005];
    void dfs(int i,vector<vector<pair<node*, int>>>&connected) {
        vis[i] = 1;
        for (pair<node*,int>& p : connected[i]) {
            ans = min(ans, p.second);
            if(vis[p.first->val] == 1)continue;
            dfs(p.first->val,connected);
        }
        return;
    }
    int minScore(int N, vector<vector<int>>& r) {
        unordered_map<int, node*> mp;
        memset(vis,0,sizeof(vis));
        node* t;
        n = N;
        vector<vector<pair<node*, int>>>connected(100005); // connected node and the distance to reach there
        for (int i = 1; i <= n; i++) {
            t = new node(i);
            mp[i] = t;
        }
        node *a, *b;
        for (int i = 0; i < r.size(); i++) {
            a = mp[r[i][0]];
            b = mp[r[i][1]];
            connected[a->val].push_back({b, r[i][2]});
            connected[b->val].push_back({a, r[i][2]});
        }
        dfs(1,connected);
        return ans;
    }
};