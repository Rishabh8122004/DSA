class Solution {
public:
    string lexGreaterPermutation(string s, string t) {
        int n = s.size();
        vector<int> v(26);

        for (int i = 0; i < n; i++) {
            v[s[i] - 'a']++;
        }

        s = "";

        for (int i = 0; i < n; i++) {
            if (v[t[i] - 'a'] > 0) {
                s += t[i];
                v[t[i] - 'a']--;
            } 
            else {
                int x = t[i] - 'a';
                x++;

                while (x < 26) {
                    if (v[x] > 0) {
                        s += (char)(x + 'a');
                        v[x]--;

                        for (int j = 0; j < 26; j++) {
                            while (v[j] > 0) {
                                s += (char)(j + 'a');
                                v[j]--;
                            }
                        }

                        return s;
                    }
                    x++;
                }

                // Backtrack in the already matched prefix
                for (int j = s.size() - 1; j >= 0; j--) {
                    v[s[j] - 'a']++;

                    int y = s[j] - 'a' + 1;
                    int d = s.size();

                    while (y < 26) {
                        if (v[y] > 0) {
                            s[j] = (char)(y + 'a');
                            v[y]--;

                            j++;

                            for (int k = 0; k < 26; k++) {
                                while (v[k] > 0) {
                                    if(j<d){s[j] = (char)(k+'a');j++;}
                                    else s += (char)(k + 'a');
                                    v[k]--;
                                }
                            }

                            return s;
                        }
                        y++;
                    }
                }

                return "";
            }
        }

        v.clear();
        v.resize(26);

        if (s == t) {
            int i = n - 2;
            v[s[n - 1] - 'a']++;

            while (i >= 0) {
                v[s[i] - 'a']++;

                if (s[i] < s[i + 1]) {
                    int x = s[i] - 'a' + 1;

                    while (x < 26) {
                        if (v[x] > 0) {
                            s[i] = (char)(x + 'a');
                            v[x]--;
                            i++;
                            break;
                        }
                        x++;
                    }

                    for (int k = 0; k < 26; k++) {
                        while (v[k] > 0) {
                            s[i] = (char)(k + 'a');
                            i++;
                            v[k]--;
                        }
                    }

                    return s;
                }

                i--;
            }
        }

        return "";
    }
};