class Solution {
public:
    double findMedianSortedArrays(vector<int>& n1, vector<int>& n2) {
        double ans;
        vector<int> v;
        int i = 0, j = 0;
        while (i < n1.size() && j < n2.size()) {
            if (n1[i] <= n2[j]) {
                v.push_back(n1[i]);
                i++;
            } else {
                v.push_back(n2[j]);
                j++;
            }
        }
        if (j >= n2.size()) {
            while (i < n1.size()) {
                v.push_back(n1[i]);
                i++;
            }
        }
        if (i >= n1.size()) {
            while (j < n2.size()) {
                v.push_back(n2[j]);
                j++;
            }
        }
        int n = v.size();
        if (n % 2 == 0) {
            ans = ((double)(v[n / 2] + v[(n / 2) - 1]) / 2);
        } else {
            ans = v[n / 2];
        }
        for(int i = 0;i<n;i++)cout<<v[i]<<" ";
        return ans;
    }
};