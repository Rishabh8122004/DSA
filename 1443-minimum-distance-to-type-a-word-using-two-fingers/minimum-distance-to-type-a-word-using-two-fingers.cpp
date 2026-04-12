class Solution {
public:
    int dp[301][27][27];
    int get_distance(int ch1,int ch2) {
        int r1 = ch1/6,c1 = ch1%6,r2 = ch2/6,c2 = ch2%6;
        return abs(r1-r2) + abs(c1-c2);
    }
    int solve(string& w, int i, int f1,int f2) {
        if (i == w.size()) return 0;

        // cordinates of current word character
        int curr = w[i]-'A'; // current character

        int move_f1, move_f2;

        if (dp[i][f1][f2] != -1) return dp[i][f1][f2];
        else if ((f1 == 26) && (f2 == 26)) { // both fingers free
            return dp[i][f1][f2] = solve(w, i + 1, curr,f2); // using f1 to type word char
        }
        else if (f2 == 26) { // finger 2 is free 
            move_f1 = get_distance(f1,curr) + solve(w, i + 1, curr,f2);
            move_f2 = solve(w, i + 1, f1, curr);
        }
        else if ((f1 != 26) && (f2 != 26)) { // both fingers are being used
            move_f1 = get_distance(f1,curr) + solve(w, i + 1, curr, f2);
            move_f2 = get_distance(f2,curr) + solve(w, i + 1, f1, curr);
        }
        return dp[i][f1][f2] = min(move_f1, move_f2);
    }
    int minimumDistance(string w) {
        int n = w.size();
        /*
         for calculating row and column of a character
          row = (ch-'A')/6;
          col = (ch-'A')%6;
        */
        memset(dp, -1, sizeof(dp));
        return solve(w, 0, 26, 26); //string w , i = 0, f1 = 26 and f2 = 26 means both fingers are in the air
    }
};