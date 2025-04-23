class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlength = 0;
        int n = s.size();
        for(int i = 0;i<n;i++)
        {
        for(int j = 1;j<=n-i;j++)
        {
            string p = s.substr(i,j); // declaring a string to access sub-string
            int a = p.size(); // getting substring size
            bool check = true; // apllying check if sub string is favourable or not
            vector<int> v(256);
            for(int i = 0;i<p.size();i++)
            {
                int x = p[i];
                v[x]++;
                if(v[x]>1) {check = false; break;}
            }
            if(check == false)break;
            if(check && maxlength < a)
            {
                maxlength = a;
            }
        }
        }
        return maxlength;
    }
};