//solving using MORRIS TRAVERSAL : 
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* prev = NULL,*first = NULL,*second = NULL;
        while(curr){//inorder traverse
        if(curr->left){
            TreeNode* pred = curr->left;
            while(pred->right && pred->right != curr){
                pred = pred->right;
            }
            if(pred->right == NULL){
                pred->right = curr;
                curr = curr->left;
            }
            else if(pred->right == curr){
                pred->right = NULL;
                if (prev && prev->val > curr->val) {
                    if (!first) first = prev;
                    second = curr;
                }
                prev = curr;
                curr = curr->right;
            }
        }
        else{//can't go any left
            // marking our curr as prev 
            if (prev && prev->val > curr->val) {
                if (!first) first = prev;
                second = curr;
            }
            prev = curr;
            curr = curr->right;
        }
       } 
       if(first && second){swap(first->val,second->val);}
    }
};