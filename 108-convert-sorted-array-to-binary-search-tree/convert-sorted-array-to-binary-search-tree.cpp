class Solution {
public:
    TreeNode* build(vector<int>& nums,int lo , int hi){
        if(lo>hi)return NULL;
        int mid = (lo+hi)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(nums,lo,mid-1);
        root->right = build(nums,mid+1,hi);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        int lo = 0,hi = n-1;
        return build(nums,lo,hi);
    }
};