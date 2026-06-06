class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& m) {
        int a = m.size(), b = m[0].size();
        unordered_set<int> st; // using set for tracking unique values in the matrix
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (m[i][j] != 0)
                    st.insert(m[i][j]);
            }
        }
        // building a matrix which stores if there is a greater value than the
        // element or not.
        unordered_map<int, vector<vector<int>>> mp; // har ek unique element ki apni matrix hogi usme row-wise prefix sum use krenge... jo btaega ki current row me kitne elements hai jo current unique element se bade hai.....esa hum sirf isliye kr skte hai kyuki total maxinum number of unique elements 200 honge or memory jaegi maximum 200*200*200 = 8*10^6 , jo ki chalega.. 

        for (auto p : st) { // for every unique element 'p'

            mp[p] = vector<vector<int>>(a, vector<int>(b, 0)); // size declaration of the matrix of the element
            auto& k = mp[p];
            for (int i = 0; i < a; i++) {
                for (int j = 0; j < b; j++) {
                    if (m[i][j] > p) // agar element bada hai to jo element ki matrix hai usme current position pe  +1
                        k[i][j] = 1;
                    if (j > 0)
                        k[i][j] += k[i][j - 1]; // prefix sum , yani pehle kitne bade elements aa chuke hai
                }
            }
        }
        int ans = 0; // final answer 

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) { // checking for every elements .. kyuki uska area alag hoga... 
                if (m[i][j] == 0) // only check for non - zero elements
                    continue;
                int ele = m[i][j];
                auto& k = mp[ele]; // & ka use krne se memory usage kam kr skte hai.. seedha pointer addres pe point krega

                // ye neeche us element ka area decide kra hai apan ne....  
                int up = max(0, i - ele);
                int down = min(a - 1, i + ele);
                int l = max(0, j - ele);
                int r = min(b - 1, j + ele);
                bool f = true; // assume kr rhe hai ki yahi local max. element hai.. 
                int L = l, R = r; // temp. l & r taki renew krte time asani rhe...
                for (int row = up; row <= down && f; row++) {
                    l = L;
                    r = R;
                    if (row == up) { // corner case remove yani vo position jisme row or col ki value x k barabar ho..
                        if (i - up == ele && j - l == ele)
                            l++;
                        if (i - up == ele && r - j == ele)
                            r--;
                    }
                    if (row == down) {
                        if (down - i == ele && j - l == ele)
                            l++;
                        if (down - i == ele && r - j == ele)
                            r--;
                    }
                    // detecting agar current row me koi bada element hai kya.. agar hai to f = false & break the loop
                    int x = k[row][r];
                    if (l > 0)
                        x -= k[row][l - 1];

                    if (x > 0)
                        f = false;
                }
                if (f)
                    ans++;
            }
        }
        return ans;
    }
};