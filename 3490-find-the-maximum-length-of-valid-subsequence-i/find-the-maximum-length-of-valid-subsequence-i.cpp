class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        if (n == 2) return 2; // 2 is the obvious answer without a doubt. 

        int e = 0, o = 0; // no. of even,odd elements
        int len = 1;      // including first element no matter even or odd
        bool last = (nums[0] % 2 == 0 ? true:false); // false means odd, true means even
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) { // if even
                e++; // increase even
                if (!last) { // if the last picked element was odd then we can pick this one..
                    len++; // increasing length
                    last = true; // changing last element
                }
            } else { // if element is odd
                o++; // increasing odd
                if (last) { // if last element was even
                    len++; // length ++
                    last = false; // changing last element picked as odd .. 
                }
            }
        }
        return max(len, max(o, e)); // return the maximum amoung (length of alternative even,odd) , no. of even, no. of odd.
    }
};