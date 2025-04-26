class Solution {
public:
    int atMostK(const vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> freq(20001, 0); // frequency array to track counts
        int ans = 0, i = 0;
        
        for (int j = 0; j < n; j++) {
            if (freq[nums[j]] == 0) k--; // found a new distinct element
            freq[nums[j]]++; // add current element to window
            
            // shrink the window if more than k distinct elements
            while (k < 0) {
                freq[nums[i]]--; // remove element at left
                if (freq[nums[i]] == 0) k++; // distinct element fully removed
                i++; // move left pointer forward
            }
            
            ans += (j - i + 1); // add all subarrays ending at j
        }
        
        return ans; // return total count
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // exactly K = atMost(K) - atMost(K-1)
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
