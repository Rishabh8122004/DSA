
class Solution {
public:
    // Stores the nodes with each character encountered along the current DFS path.
    vector<stack<int>> last_seen{26};

    // First DFS: Find the nearest ancestor having the same character.
    void dfs(int i, vector<vector<int>>& child, string& s, vector<int>& p) {
        int c = s[i]-'a';  // Convert character into an index (0-25).

        // The stack top gives the closest ancestor with the same character.
        if (!last_seen[c].empty()) {
            p[i] = last_seen[c].top();
        }

        last_seen[c].push(i);  // Include current node in the DFS path.

        // Explore all children while maintaining the current ancestor path.
        for (int j = 0; j < child[i].size(); j++) {
            dfs(child[i][j], child, s, p);
        }

        // Backtrack: Remove current node before exploring another branch.
        last_seen[c].pop();
        return;
    }

    // Second DFS: Calculate the subtree size of each node.
    int size(int i, vector<int>& ans, vector<vector<int>>& child) {
        int total = 1;  // Count the current node.

        // Add the subtree sizes of all its children.
        for(int j = 0;j<child[i].size();j++){
            total += size(child[i][j],ans,child);
        }

        // Store and return the total subtree size.
        return ans[i] = total;
    }

    vector<int> findSubtreeSizes(vector<int>& p, string s) {
        int n = p.size();

        // Adjacency list: child[i] stores all direct children of node i.
        vector<vector<int>> child(n);

        // Build the original tree using the parent array.
        for (int i = 1; i < n; i++) {
            child[p[i]].push_back(i);
        }

        // Update parent relationships based on the nearest matching ancestor.
        dfs(0, child, s, p);

        // Clear the original tree's child relationships.
        for(int i = 0;i<n;i++){
            child[i] = {};
        }

        // Rebuild the adjacency list using the updated parent array.
        for (int i = 1; i < n; i++) {
            child[p[i]].push_back(i);
        }

        // Stores the final subtree size for every node.
        vector<int> ans(n, 0);

        // Calculate subtree sizes in the modified tree.
        size(0, ans, child);

        return ans;
    }
};
