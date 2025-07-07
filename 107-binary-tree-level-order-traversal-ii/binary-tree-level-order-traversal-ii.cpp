class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)return{};
        vector<vector<int>> ans;
        vector<int>v;
        int curr = 1;
        int next = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            if(curr == 0){curr = next;next = 0;ans.push_back(v);v = {};}
            TreeNode* t = q.front();
            q.pop();
            v.push_back(t->val);
            curr--;
            if (t->left){
                q.push(t->left);
                next++;
            }
            if (t->right){
                q.push(t->right);
                next++;
            }
        }
        ans.push_back(v);
        int i = 0,j =  ans.size()-1;
        while(i<j){
            swap(ans[i],ans[j]);
            i++;j--;
        }
        return ans;
    }
};