class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        if (k == 1)
            return true;
        unordered_map<int, int>
            mp; // (arr[i]%k) and number of elements having same result
        for (int i = 0; i < arr.size(); i++) {
            mp[((arr[i] % k)+k)%k]++;
        }
        if (mp[0] % 2 != 0)
            return false; // odd number of elements with divisiblity by k
        for (auto p : mp) {
            if (p.first == 0) continue;
            if (mp[k - p.first] != p.second) return false;
        }
        return true;
    }
};