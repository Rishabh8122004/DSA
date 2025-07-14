class Solution {
public:
    void fill_parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&mp,TreeNode* parent,int & start,TreeNode*&first){
        if(!root)return;
        mp[root] = parent;
        if(root->val == start)first = root;
        fill_parent(root->left,mp,root,start,first);
        fill_parent(root->right,mp,root,start,first);
        return;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>mp; // treenode and it's parent
        unordered_set<TreeNode*>is_infected; // will let us know if the node is alread infected
        TreeNode* first; // node with the value start
        fill_parent(root,mp,NULL,start,first); // parent of root is NULL
        queue<pair<TreeNode*,int>>q; // contains the freshly infected nodes..haha
        is_infected.insert(first);
        int ans = 0;
        q.push({first,0});
        while(!q.empty()){
            TreeNode *curr = q.front().first,*p,*l,*r;
            int curr_level = q.front().second;
            is_infected.insert(curr);
            ans = max(ans,curr_level);
            q.pop();
            p = mp[curr];
            l = curr->left;
            r = curr->right;
            if(p && (is_infected.find(p) == is_infected.end()))q.push({p,curr_level+1});
            if(l && (is_infected.find(l) == is_infected.end()))q.push({l,curr_level+1});
            if(r && (is_infected.find(r) == is_infected.end()))q.push({r,curr_level+1});
        }
        return ans;
    }
};