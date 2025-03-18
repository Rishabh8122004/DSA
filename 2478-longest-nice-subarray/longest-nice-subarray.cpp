class Solution {
public:
    void removeBits(vector<int> &v, int x) {
        int k = 0;
        while (x > 0) {
            if (x % 2 == 1) v[k] = 0;  // Reset bit positions
            k++;
            x /= 2;
        }
    }

    bool canAdd(vector<int> &v, int x) {
        int k = 0;
        while (x > 0) {
            if (x % 2 == 1 && v[k] == 1) return false;  // Conflict found
            k++;
            x /= 2;
        }
        return true;
    }

    void addBits(vector<int> &v, int x) {
        int k = 0;
        while (x > 0) {
            if (x % 2 == 1) v[k] = 1;
            k++;
            x /= 2;
        }
    }

    int longestNiceSubarray(vector<int>& nums) {
        vector<int> v(40, 0);
        int i = 0, j = 0, ans = 1;

        while (j < nums.size()) {
            // Try adding nums[j]
            while (!canAdd(v, nums[j])) {
                removeBits(v, nums[i]);  // Remove nums[i] from bitset
                i++;  // Move left pointer
            }
            
            addBits(v, nums[j]);  // Add nums[j] to bitset
            ans = max(ans, j - i + 1);  // Update max length
            j++;
        }
        return ans;
    }
};
