class Solution {
public:
    int numberOfSubstrings(string word) {
        // using sliding window technique;
        int ans = 0;
        int n = word.size();
        int a = 0, b = 0, c = 0;
        int p = 0, q = 0;
        int v = n;
        char ch;
        while (q < n) {
            ch = word[q];
            if (ch == 'a')
                a++;
            else if (ch == 'b')
                b++;
            else if (ch == 'c')
                c++;
            while (p < n && a > 0 && b > 0 && c > 0) {
                ans += (n - q);
                ch = word[p];
                if (ch == 'a')
                    a--;
                else if (ch == 'b')
                    b--;
                else if (ch == 'c')
                    c--;
                p++;
            }
            q++;
        }
        return ans;
    }
};