class Solution {
public:
    bool solve(vector<int>& arr, int start, vector<bool>& v) {
        if (start > arr.size() - 1 || start < 0)
            return false;
        if (arr[start] == 0)
            return true;
        if(v[start]) return false;
        v[start] = true;
        if (solve(arr, start + arr[start],v))
            return true;
        if (solve(arr, start - arr[start],v))
            return true;
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> v(arr.size(),false);
        return solve(arr, start, v);
    }
};