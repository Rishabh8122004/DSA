class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        priority_queue<int>p,t;
        int i = 0;
        while(i<players.size() || i<trainers.size()){
            if(i<players.size()){
                p.push(players[i]);
            }
            if(i<trainers.size()){
                t.push(trainers[i]);
            }
            i++;
        }
        int ans = 0;
        while(!p.empty() && !t.empty()){
            if(p.top()<=t.top()){
                ans++;
                t.pop();
            }
            p.pop();
        }
        return ans;
    }
};