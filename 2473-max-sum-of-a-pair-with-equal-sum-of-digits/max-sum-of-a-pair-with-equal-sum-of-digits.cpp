class Solution {
public:
    // Function to calculate the sum of digits of a number
    int findsum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10; // Add the last digit to sum
            n /= 10;       // Remove the last digit
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> sum; // Stores {digit sum, index} pairs

        // Compute digit sum for each number and store it with its index
        for (int i = 0; i < n; i++) {
            sum.push_back({findsum(nums[i]), i});
        }

        // Sort pairs based on digit sum (ascending order)
        sort(sum.begin(), sum.end());

        int maxsum = -1; // Stores the maximum sum of two numbers with the same digit sum

        // Iterate through sorted array to find pairs with the same digit sum
        for (int i = 0; i < n - 1; i++) {
            int m = nums[sum[i][1]]; // Store the first number of the current group

            // Check consecutive numbers with the same digit sum
            while (i < n - 1 && sum[i][0] == sum[i + 1][0]) {
                m = max(m, nums[sum[i][1]]); // Track the maximum number in this group
                maxsum = max(maxsum, m + nums[sum[i + 1][1]]); // Update maxsum
                i++; // Move to the next element
            }
        }
        return maxsum;
    }
};
