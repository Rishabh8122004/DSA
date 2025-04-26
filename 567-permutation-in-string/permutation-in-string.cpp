class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size();
        int m = s1.size();
        vector<int> v(26);
        for(int i = 0;i<m;i++){
            v[(int)s1[i]-97]++;
        }
        for(int i = 0;i<n-m+1;i++){
            vector<int> v2(26);
            for(int j = i;j<i+m;j++){
                v2[(int)s2[j]-97]++;
            }
            if(v == v2) return true;
        }
        return false;
    }
};