class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        // using sliding window technique;
        long long int ans = 0;
        int n = word.size();
        int a = 0, e = 0, i = 0, o = 0, u = 0; // vowels
        int cons = 0;                          // for consonants;
        int p = 0, q = 0;
        int v = n;
        vector<int> consonant(n,n);
        for (int i = n - 1; i >= 0; i--) {
            char ch = word[i];
            consonant[i] = v;
            if (ch != 'u' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'a') v = i; 
        }
        char ch;
        while (q<n) {
            ch = word[q];
                if (ch == 'a')
                    a++;
                else if (ch == 'e')
                    e++;
                else if (ch == 'i')
                    i++;
                else if (ch == 'o')
                    o++;
                else if (ch == 'u')
                    u++;
                else {
                    cons++;
                }
            while (p<n && (cons > k)) {
                ch = word[p];
                if (ch == 'a')
                    a--;
                else if (ch == 'e')
                    e--;
                else if (ch == 'i')
                    i--;
                else if (ch == 'o')
                    o--;
                else if (ch == 'u')
                    u--;
                else {
                    cons--;
                }
                p++;
            }
            while (p<n && a > 0 && e > 0 && i > 0 && o > 0 && u > 0 && cons == k) {
                ans += (consonant[q] - q);
                ch = word[p];
                if (ch == 'a')
                    a--;
                else if (ch == 'e')
                    e--;
                else if (ch == 'i')
                    i--;
                else if (ch == 'o')
                    o--;
                else if (ch == 'u')
                    u--;
                else {
                    cons--;
                }
                p++;
            }
            q++;
        }
        return ans;
    }
};