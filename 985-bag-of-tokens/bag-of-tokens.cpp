class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int power) {
        sort(t.begin(),t.end());
        int ans = 0;
        int score = 0;
        int i = 0,j = t.size()-1;
        while(i<=j){
            if(power>=t[i]){
                power-=t[i];
                score++;
                i++;
            }
            else if(power<t[i] && score>0){
                power+=t[j];
                j--;
                score--;
            }
            else break;
            ans = max(ans,score);
        }
        return ans;
    }
};