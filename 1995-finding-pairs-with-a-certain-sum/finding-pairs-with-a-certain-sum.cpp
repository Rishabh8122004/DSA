class FindSumPairs {
public:
    vector<int> p, q;
    map<int, int> mp; // value from q -> frequency

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->p = nums1;
        this->q = nums2;
        for (int num : q) {
            mp[num]++;
        }
    }

    void add(int index, int val) {
        int old_val = q[index];
        mp[old_val]--;
        q[index] += val;
        mp[q[index]]++;
    }

    int count(int tot) {
        int ans = 0;
        for (int num : p) {
            int complement = tot - num;
            ans += mp[complement];
        }
        return ans;
    }
};
