class Solution {
public:
    int max_depth = 0;
    class Node {
    public:
        int val;
        vector<Node*> v;
        Node* parent = NULL;
        Node(int val) { this->val = val; }
    };
    int depth(Node* root) {
        if (root == NULL)
            return 0;
        int ans = 0;
        for (Node* node : root->v) {
            ans = max(ans, depth(node));
        }
        return ans + 1;
    }
    int assignEdgeWeights(vector<vector<int>>& e) {
        unordered_map<int, Node*> mp;
        int p, c;
        Node *par, *child;
        for (int i = 0; i < e.size(); i++) {
            p = e[i][0];
            c = e[i][1];
            if (!mp.count(p)) {
                par = new Node(p);
                mp[p] = par;
            }
            if (!mp.count(c)) {
                child = new Node(c);
                mp[c] = child;
            }
            par = mp[p];
            child = mp[c];
            par->v.push_back(child);
            child->parent = par;
        }
        Node* root = mp[e[0][0]];
        while (root->parent) {
            root = root->parent;
        }
        max_depth = depth(root) - 2;
        long long ans = 1, base = 2;
        const long long MOD = 1e9 + 7;

        while (max_depth) {
            if (max_depth & 1) {
                ans = (ans * base) % MOD;
            }

            base = (base * base) % MOD;
            max_depth >>= 1;
        }

        return (int)ans;
    }
};