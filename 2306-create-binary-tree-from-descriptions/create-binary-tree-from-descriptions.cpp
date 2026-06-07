/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        TreeNode* root = NULL;
        unordered_map<int, TreeNode*> mp;
        unordered_map<TreeNode*,TreeNode*>par;
        for (int i = 0; i < d.size(); i++) {
            if (!mp.count(d[i][0])) {
                mp[d[i][0]] = new TreeNode(d[i][0]);
            }
            if (!mp.count(d[i][1])) {
                mp[d[i][1]] = new TreeNode(d[i][1]);
            }
            TreeNode* parent = mp[d[i][0]],*child = mp[d[i][1]];
            par[child] = parent;
            if(d[i][2] == 0){
                parent -> right = child;
            }
            else parent -> left = child;
        }
        root = mp[d[0][0]];
        while(par.count(root)){
            root = par[root];
        }
        return root;
    }
};