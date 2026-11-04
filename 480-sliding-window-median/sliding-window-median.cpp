class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> ans;
        multiset<double> left, right;
        for (int i = 0; i < k; i++) {
            if (left.size() <= right.size()) {
                left.insert(nums[i]);
            } else {
                right.insert(nums[i]);
            }
            while (!right.empty() && (*left.rbegin() > *right.begin())) {
                double x = *left.rbegin(), y = *right.begin();
                left.erase(left.find(x));
                right.erase(right.find(y));
                right.insert(x);
                left.insert(y);
            }
        }
        if (k % 2 == 1)
            ans.push_back(*left.rbegin());
        else
            ans.push_back((*left.rbegin() + *right.begin()) / 2.0);
        int i = 0, j = k;
        while (j < n) {
            if (nums[i] > *left.rbegin()) {
                right.erase(right.find(nums[i]));
            } else {
                left.erase(left.find(nums[i]));
            }

            if (left.size() <= right.size()) {
                left.insert(nums[j]);
            } else {
                right.insert(nums[j]);
            }
            while (!right.empty() && (*left.rbegin() > *right.begin())) {
                double x = *left.rbegin(), y = *right.begin();
                left.erase(left.find(x));
                right.erase(right.find(y));
                right.insert(x);
                left.insert(y);
            }
            j++;
            i++;
            if (k % 2 == 1)
                ans.push_back(*left.rbegin());
            else
                ans.push_back((*left.rbegin() + *right.begin()) / 2.0);
        }
        return ans;
    }
};