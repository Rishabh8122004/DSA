class Solution {
public:
    int rangeSumBST(TreeNode* root, int lo, int hi) {
        if(!root)return 0;
        int sum = (root->val >=lo && root->val <= hi)?root->val : 0;
        sum+=rangeSumBST(root->left,lo,hi);
        sum+=rangeSumBST(root->right,lo,hi);
        return sum;
    }
};