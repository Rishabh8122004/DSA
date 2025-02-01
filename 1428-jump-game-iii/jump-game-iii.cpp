class Solution {
public:
    bool solve(vector<int>& arr, int start, vector<bool>& v) {
        if (start > arr.size() - 1 || start < 0) // Out of bounds
            return false;
        if (arr[start] == 0) // Found target
            return true;
        if (v[start]) return false; // Already visited, avoid cycles

        v[start] = true; // Mark as visited

        // Try jumping forward and backward
        return solve(arr, start + arr[start], v) || solve(arr, start - arr[start], v);
    }

    bool canReach(vector<int>& arr, int start) {
        vector<bool> v(arr.size(), false); // Visited array
        return solve(arr, start, v);
    }
};
