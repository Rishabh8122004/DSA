class Solution {
public:
    TreeNode* solve(vector<int>& pre,int prelo,int prehi, vector<int>& in,int inlo,int inhi){
        if(prelo>prehi)return NULL;
        TreeNode* root = new TreeNode(pre[prelo]);
        if(prelo == prehi)return root;
        if(prelo == prehi){return root;}
        int idx = prelo;
        for(int i = inlo;i<=inhi;i++){
            if(in[i] == pre[prelo]){idx = i;break;}
        }
        root->left = solve(pre,prelo+1,prelo+(idx-inlo),in,inlo,idx-1);
        root->right = solve(pre,prelo+(idx-inlo)+1,prehi,in,idx+1,inhi);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        TreeNode* root = solve(pre,0,pre.size()-1,in,0,in.size()-1);
        return root; 
    }
};