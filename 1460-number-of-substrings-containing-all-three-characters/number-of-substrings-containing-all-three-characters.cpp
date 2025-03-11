class Solution {
public:
    int numberOfSubstrings(string s) {
        // using sliding window technique;
        int ans = 0;
        int n = s.size();
        int a = 0, b = 0, c = 0;
        int i = 0, j = 0;
        char ch;
        while (j < n) {
            ch = s[j];
            if (ch == 'a')
                a++;
            else if (ch == 'b')
                b++;
            else if (ch == 'c')
                c++;
            while (i < n && a > 0 && b > 0 && c > 0) {
                ans += (n - j);
                ch = s[i];
                if (ch == 'a')
                    a--;
                else if (ch == 'b')
                    b--;
                else if (ch == 'c')
                    c--;
                i++;
            }
            j++;
        }
        return ans;
    }
};