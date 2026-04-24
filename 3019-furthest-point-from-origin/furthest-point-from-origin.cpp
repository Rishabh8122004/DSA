class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cnt = 0,r = 0,l = 0;
        for(int i = 0;i<moves.size();i++){
            if(moves[i] == 'L')l++;
            else if(moves[i] == 'R')r++;
            else cnt++;
        }
        return cnt+max(r,l)-min(r,l);
    }
};