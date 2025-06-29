class Solution {
public:
    void getfreq(TreeNode* root,vector<int>&nv,vector<int>&pv){
        if(!root)return;
        if(root->val >= 0)pv[root->val]++;
        else nv[abs(root->val)]++;
        getfreq(root->left,nv,pv);
        getfreq(root->right,nv,pv);
        return;
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>nv(1e5+1),pv(1e5+1);//negetive vector and positive vector to store frequencies
        getfreq(root,nv,pv);
        int mf = 0;//maxfreq
        vector<int>ans;
        for(int i = 0;i<nv.size();i++){
            if(mf>nv[i])continue;
            if(mf<nv[i]){ans = {};}
            ans.push_back(-1*i);
            mf = max(mf,nv[i]);
        }
        for(int i = 0;i<pv.size();i++){
            if(mf>pv[i])continue;
            if(mf<pv[i]){ans = {};}
            ans.push_back(i);
            mf = max(mf,pv[i]);
        }
        return ans;
    }
};