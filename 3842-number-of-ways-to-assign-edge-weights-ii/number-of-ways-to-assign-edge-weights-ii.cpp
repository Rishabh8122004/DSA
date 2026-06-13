class Solution {
public:
    class Node {
    public:
        int val;
        int depth = 0;
        vector<Node*> v;  // child nodes
        vector<Node*> up; // binary lifting
        Node* parent = NULL;
        Node(int val) { this->val = val; }
    };

    void set_depth(Node* node, int d) {
        node->depth = d;

        node->up.resize(18);

        if (node->parent) {
            node->up[0] = node->parent;
        }

        for (int j = 1; j < 18; j++) { // binary lifting
            if (node->up[j - 1])
                node->up[j] = node->up[j - 1]->up[j - 1];
        }

        for (Node* child : node->v) {
            set_depth(child, d + 1);
        }
    }

    Node* lowest_ancesstor(Node* a, Node* b) {

        if (a->depth < b->depth)
            swap(a, b);

        int diff = a->depth - b->depth;

        for (int j = 17; j >= 0; j--) {
            if (diff & (1 << j))
                a = a->up[j];
        }

        if (a == b)
            return a;

        for (int j = 17; j >= 0; j--) {
            if (a->up[j] && a->up[j] != b->up[j]) {
                a = a->up[j];
                b = b->up[j];
            }
        }

        return a->parent;
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& e,
                                  vector<vector<int>>& q) {
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

        set_depth(root, 0); // setting the depth of each node.

        vector<int> ans(q.size());

        int n = e.size();
        vector<long long> power(n);
        power[0] = 1;

        for (int i = 1; i < power.size(); i++) {
            power[i] = (power[i - 1] * 2) % (1000000007);
        }

        Node *a, *b;
        for (int i = 0; i < q.size(); i++) {
            a = mp[q[i][0]];
            b = mp[q[i][1]];
            Node* lca = lowest_ancesstor(a, b);

            int len = a->depth + b->depth - (2 * (lca->depth));

            if (len == 0) {
                ans[i] = 0;
            } else {
                ans[i] = power[len - 1];
            }
        }

        return ans;
    }
};