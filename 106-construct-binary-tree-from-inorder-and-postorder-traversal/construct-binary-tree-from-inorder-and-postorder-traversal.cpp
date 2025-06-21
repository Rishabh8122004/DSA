class Solution {
public:
    TreeNode* solve(vector<int>& post,int postlo,int posthi,vector<int>& in,int inlo,int inhi){
        if(postlo>posthi)return NULL;
        TreeNode* root = new TreeNode(post[posthi]);
        if(postlo == posthi)return root;
        int idx = inlo;
        while(idx<=inhi){
            if(post[posthi] == in[idx])break;
            idx++;
        }
        root->left = solve(post,postlo,postlo+(idx-inlo-1),in,inlo,idx-1);
        root->right = solve(post,posthi-(inhi-idx),posthi-1,in,idx+1,inhi);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n = in.size();
        return solve(post,0,n-1,in,0,n-1);
    }
};