class Solution {
public:
    bool isvalid(int x, unordered_map<int, int> mp) {
        while (x) {
            if (mp[x % 10] == 0)
                return false;
            mp[x % 10]--;
            x /= 10;
        }
        return true;
    }
    vector<int> findEvenNumbers(vector<int>& d) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (int e : d)
            mp[e]++;
        for (int i = 100; i < 1000; i+=2) { // possible range of outcomes
            if ( i%2 == 0 && isvalid(i, mp)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};