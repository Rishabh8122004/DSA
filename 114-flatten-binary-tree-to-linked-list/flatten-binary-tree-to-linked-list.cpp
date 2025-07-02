class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root,*l;
        while (curr) {
            if (curr->left) {
                TreeNode* r = curr->right;
                curr->right = curr->left;
                TreeNode* pred = curr->left;
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