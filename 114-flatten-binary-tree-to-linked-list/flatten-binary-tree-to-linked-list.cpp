class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
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
                    curr = curr->left;
                }
            } else {
                curr = curr->right;
            }
        }
        TreeNode* temp = root;
        while (temp) {
            temp->left = NULL;
            temp = temp->right;
        }
    }
};