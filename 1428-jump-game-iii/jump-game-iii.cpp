class Solution {
public:
    bool solve(vector<int>& arr, int start, vector<int>& v) {
        if (start > arr.size() - 1 || start < 0)
            return false;
        if (arr[start] == 0)
            return true;
        for(int i = 0;i<v.size();i++){if(start == v[i])return false; }
        v.push_back(start);
        if (solve(arr, start + arr[start],v))
            return true;
        if (solve(arr, start - arr[start],v))
            return true;
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int> v;
        return solve(arr, start, v);
    }
};