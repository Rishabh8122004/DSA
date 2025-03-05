class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> v;
        int i = num.size() - 1;
        while (k > 0 || i >= 0) {
            if (k > 0 && i >= 0) {
                int x = (k % 10 + num[i]);
                k /= 10;
                if (x >= 10) {
                    k++;
                    x %= 10;
                }
                v.push_back(x);
                i--;
            } else if (k == 0 && i >= 0) {
                v.push_back(num[i]);
                i--;
            } else if (i < 0 && k > 0) {
                v.push_back(k % 10);
                k /= 10;
            }
        }
        i = 0;
        int j = v.size() - 1;
        while (i < j) {
            swap(v[i], v[j]);
            i++;
            j--;
        }
        return v;
    }
};