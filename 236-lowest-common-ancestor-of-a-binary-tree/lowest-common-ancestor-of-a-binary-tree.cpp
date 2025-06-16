class Solution {
public:
    void solve(TreeNode* root, vector<TreeNode*>& vec, TreeNode* &p1, bool &flag) {
        if (flag || !root) return;

        vec.push_back(root);
        if (root == p1) {
            flag = true;
            return;
        }

        solve(root->left, vec, p1, flag);
        solve(root->right, vec, p1, flag);

        if (!flag) vec.pop_back();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP, pathQ;
        bool flag = false;

        solve(root, pathP, p, flag);
        flag = false;
        solve(root, pathQ, q, flag);

        TreeNode* ans = nullptr;
        int i = 0;
        while (i < pathP.size() && i < pathQ.size()) {
            if (pathP[i] == pathQ[i]) {
                ans = pathP[i];
            } else break;
            i++;
        }
        return ans;
    }
};
