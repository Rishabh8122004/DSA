/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void level_wise_arrangement(int level,vector<vector<TreeNode*>>&v,TreeNode*root){
        if(!root)return;
        if(v.size()==level){
            v.push_back({});
        }
        v[level].push_back(root);
        level_wise_arrangement(level+1,v,root->left);
        level_wise_arrangement(level+1,v,root->right);
        return;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int level = 0;
        vector<vector<TreeNode*>>v;
        level_wise_arrangement(level,v,root);
        unordered_map<int,TreeNode*>mp;
        int n = v.size()-1;
        for(int i = 0;i<v[n].size();i++){
            mp.insert({v[n][i]->val,v[n][i]});
        }
        v.pop_back();
        while(mp.size()>1 && v.size()){
            n--;
            for(int i = 0;i<v[n].size();i++){
                int x = -1,y = -1;
                if(v[n][i]->left){
                    x = v[n][i]->left->val;
                }
                if(v[n][i]->right){
                    y = v[n][i]->right->val;
                }
                if(mp.find(x) != mp.end()){
                    mp.insert({v[n][i]->val,v[n][i]});
                    mp.erase(x);
                }
                if(mp.find(y) != mp.end()){
                    mp.insert({v[n][i]->val,v[n][i]});
                    mp.erase(y);
                }
            }
            v.pop_back();
        }
        for(auto p:mp){
            return p.second;
        }
        return NULL;
    }
};