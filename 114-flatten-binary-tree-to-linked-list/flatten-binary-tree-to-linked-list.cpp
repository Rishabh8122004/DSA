class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root,*l,*pred,*r;
        while (curr) {
            if (curr->left) {
                r = curr->right;
                curr->right = curr->left;
                pred = curr->left;
                while (pred->right != NULL) {
                    pred = pred->right;
                }
                if (pred->right == NULL) {
                    pred->right = r;
                    l = curr->left;
                    curr->left = NULL;
                    curr = l;
                }
            } else {
                curr = curr->right;
            }
        }
        return;
    }
};