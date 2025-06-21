class Solution {
public:
    TreeNode* solve(vector<int>& pre,int prelo,int prehi,vector<int>& post,int postlo,int posthi){
        if(prelo>prehi)return NULL;
        TreeNode* root = new TreeNode(pre[prelo]);
        if(prelo == prehi)return root;
        int idx = postlo;
        while(idx<=posthi){
            if(pre[prelo+1] == post[idx])break;
            idx++;
        }
        root->left = solve(pre,prelo+1,prelo+1+(idx-postlo),post,postlo,idx);
        root->right = solve(pre,prelo+1+(idx-postlo)+1,prehi,post,idx+1,posthi-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        return solve(pre,0,n-1,post,0,n-1);
    }
};