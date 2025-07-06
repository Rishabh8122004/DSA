class FindSumPairs {
public:
    vector<int> p, q;
    map<int, int> mp; // value from q -> frequency

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        p = nums1;
        q = nums2;
        for (int num : q) {
            mp[num]++;
        }
    }

    void add(int index, int val) {
        mp[q[index]]--;
        q[index] += val;
        mp[q[index]]++;
    }

    int count(int tot) {
        int ans = 0;
        for (int num : p) {
            if(mp.count(tot-num))
            ans += mp[tot - num];
        }
        return ans;
    }
};
