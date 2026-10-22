class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;
        bool sorted = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] == n - 1) { // tracking ht eposition of maximum element , i.e. n-1
                idx = i;
            }
            if ((i + 1 < n) && (nums[i] > nums[i + 1])) // simultaneously checking if array is already sorted
                sorted = false;
        }
        if (sorted) return 0;
        // checking if array is sortable
        int i = idx + 1;
        bool inc = (nums[i % n] == 0); // if the element to the right of idx is 0 then the aray given is a rotation of increasing pattern othervise its rotation of decreasing
        while (i - idx < n - 1) { // from the idx+1 , iterate n-1 elments

        // condition to check if array is sortable of not according to the given pattern
            if (inc) {
                if (nums[i % n] + 1 != nums[(i + 1) % n])
                    return -1;
            } else {
                if (nums[(i + 1) % n] + 1 != nums[i % n])
                    return -1;
            }
            i++;
        }
        return min((1 + (n - 1 - idx + 1)),
                   (idx + 1)); // either reverse then rotate , or first rotate
                               // till n-1 reach to 0 then reverse;
    }
};