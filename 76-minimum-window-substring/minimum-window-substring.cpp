class Solution {
public:
    string minWindow(string s, string t) {
        if (s == t) return s;  // If both strings are the same, return s
        if (s.size() < t.size()) return "";  // If s is smaller than t, no window is possible

        vector<int> v(128, 0);  // Frequency array for ASCII characters
        for (int i = 0; i < t.size(); i++) { 
            v[t[i]]++;  // Increment frequency for each character in t
        }

        int tw = t.size();  // Number of characters still needed
        int i = 0, j = 0;  // Sliding window pointers
        string ans = s;  // To store the result (min window)

        while (j < s.size()) {
            // Expand the window by moving j
            while (j < s.size() && tw > 0) {
                if (v[s[j]] > 0) tw--;  // If we need this character, reduce the remaining needed
                v[s[j]]--;  // Decrement frequency
                j++;  // Move right pointer
                if (tw == 0) j--;  // If we've found all characters, stop moving j
            }

            // If we haven't found the window yet and j is out of bounds
            if (tw != 0 && ans == s && j >= s.size()) return "";

            // Shrink the window from the left
            while (tw == 0) {
                v[s[i]]++;  // Increment frequency of character at i
                if (v[s[i]] > 0) tw++;  // If this character is no longer needed, increase tw
                i++;  // Move left pointer
                if (tw == 1) {
                    i--;  // Adjust i if we need to break the loop
                    v[s[i]]--;  // Decrement the character count
                    tw--;  // Increase tw back to the required size
                    break;
                }
            }

            // Update the answer with the smallest window found
            if (tw == 0 && ans.size() > (j - i + 1)) {
                ans = s.substr(i, j - i + 1);  // Store the current window as the smallest one
            }

            // If the answer is exactly t, return it immediately
            if (ans == t) return ans;

            // Update for next iteration
            v[s[i]]++;  // Increment character count at i
            if (v[s[i]] > 0) tw++;  // If it's needed, increase tw
            i++;  // Move left pointer
            j++;  // Move right pointer
        }

        return ans;  // Return the smallest window found or empty string
    }
};
