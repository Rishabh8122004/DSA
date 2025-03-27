class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Find the dominant element using Boyer-Moore Majority Vote Algorithm
        int candidate = -1;
        int count = 0;
        
        for (int i = 0; i < n; i++) { 
            if (count == 0) {
                candidate = nums[i]; // Set new candidate if count is zero
            }
            if (nums[i] == candidate) {
                count++; // Increase count if it matches the candidate
            } else {
                count--; // Decrease count if different
            }
        }
        
        // Step 2: Count total occurrences of the dominant element
        int totalCount = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == candidate) {
                totalCount++;
            }
        }
        
        // Step 3: Compute prefix counts for the dominant element
        vector<int> countFront(n, 0); // Stores count from the front
        vector<int> countBack(n, 0);  // Stores count from the back
        
        // Fill countFront: Count occurrences from start to index i
        if (nums[0] == candidate) {
            countFront[0] = 1;
        }
        for (int i = 1; i < n; i++) {
            countFront[i] = countFront[i - 1]; // Carry forward previous count
            if (nums[i] == candidate) {
                countFront[i]++; // Increase count if current element is candidate
            }
        }
        
        // Fill countBack: Count occurrences from index i to the end
        if (nums[n - 1] == candidate) {
            countBack[n - 1] = 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            countBack[i] = countBack[i + 1]; // Carry forward next count
            if (nums[i] == candidate) {
                countBack[i]++; // Increase count if current element is candidate
            }
        }
        
        // Step 4: Find the valid split index
        for (int i = 0; i < n - 1; i++) {
            // Check if the left half (0 to i) has the dominant element in majority
            bool leftValid = (countFront[i] * 2 > (i + 1));
            // Check if the right half (i+1 to n-1) has the dominant element in majority
            bool rightValid = (countBack[i + 1] * 2 > (n - i - 1));
            
            if (leftValid && rightValid) {
                return i; // Return the first valid index found
            }
        }
        
        return -1; // No valid split found
    }
};
