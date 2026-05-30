class Solution {
public:
    int n = 50000;
    vector<int> segmentTree;
    void constructsegmentTree(){
        segmentTree.resize(4*n,0);
    }
    void update_segmentTree(int idx, int value, int i, int l, int r) { // idx is where we have to reach
        if (l == r) {
            segmentTree[i] = value;
            return;
        }

        int mid = l+(r-l)/2;
        if(idx<=mid){
            update_segmentTree(idx,value,2*i+1,l,mid); // left child 
        } else{
            update_segmentTree(idx,value,2*i+2,mid+1,r); // right child
        }

        segmentTree[i] = max(segmentTree[2*i+1],segmentTree[2*i+2]); // updating the parent
        return;
    }

    int query_segmentTree(int start,int end,int i,int l,int r){
        if(r<start || l>end)return 0; // out of range node

        if(l>=start && r <= end){
            return segmentTree[i]; // the range is smaller.
        }

        int mid = l+(r-l)/2;
        return max(query_segmentTree(start,end,2*i+1,l,mid),query_segmentTree(start,end,2*i+2,mid+1,r));
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        constructsegmentTree();
        set<int> st; // obstacles
        st.insert(0);
        vector<bool> result;
        for (auto q : queries) {
            int x = q[1];
            if (q[0] == 1) {
                auto it = st.upper_bound(x);
                int nxt = (it != st.end()) ? *it : -1; // next obstacle
                int pre = *prev(it);

                // breaking the gap and inserting the two new gaps
                update_segmentTree(x, x - pre, 0, 0, n - 1);
                update_segmentTree(nxt, nxt - x, 0, 0, n - 1);

                st.insert(x);
            } else {
                auto it = st.upper_bound(x);
                int sz = q[2];
                int pre = *prev(it);

                int maxgap = query_segmentTree(0, pre, 0, 0, n - 1);
                int best = max(maxgap, x - pre);
                result.push_back(best >= sz);
            }
        }
        return result;
    }
};