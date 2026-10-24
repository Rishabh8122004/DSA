class Solution {
public:
    int countDaysTogether(string aa, string la, string ab, string lb) {
        int aam = stoi(aa.substr(0, 2));
        int lam = stoi(la.substr(0, 2));
        int aad = stoi(aa.substr(3, 2));
        int lad = stoi(la.substr(3, 2));
        int abm = stoi(ab.substr(0, 2));
        int lbm = stoi(lb.substr(0, 2));
        int abd = stoi(ab.substr(3, 2));
        int lbd = stoi(lb.substr(3, 2));
        int ans = 0;
        int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int i = aam; i <= lam; i++) {
            for (int j = 1; j <= months[i]; j++) {
                if ((i >= lam && j > lad) || (i <= aam && j < aad))
                    continue;
                if(i < abm || i > lbm)continue;
                if ((i == lbm && j > lbd) || (i == abm && j < abd))
                    continue;
                ans++;
                cout<<i<<"-"<<j<<endl;
            }
        }
        return ans;
    }
};