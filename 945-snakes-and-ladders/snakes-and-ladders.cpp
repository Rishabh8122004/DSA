class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& b) {
        int n = b.size(); // declaring sizes..
        vector<pair<int,int>> v1((n * n) + 1);   // a vector storing positions(i,j) equivalent to count
        int c = 1;     // starting with 1
        bool f = true; // helps in moving forward and backward accordint to Boustrophedon style
        for (int i = n - 1; i >= 0; i--) {
            int j = f ? 0 : n - 1; // f decide we gonna move backward or forward... 
            while (true) { 
                v1[c].first = i;
                v1[c].second = j;
                c++;
                j += f ? 1 : -1;
                if (f && j >= n)
                    break;
                else if (!f && j < 0)
                    break;
            }
            f = !f;
        }
        queue<pair<int,int>>q;
        q.push({1,0});// first position along with it's minimum step(position,steps)
        vector<bool>visited(n*n + 1,false);
        visited[1] = true;
        while(!q.empty()){
            int pos = q.front().first , moves = q.front().second;
            q.pop();
            if(pos == n*n)return moves;
            for(int dice = 1;dice<=6;dice++){
                if(pos+dice > n*n)break;
                int next_pos = pos+dice;
                int i = v1[next_pos].first,j = v1[next_pos].second;
                if(b[i][j] != -1){
                    next_pos = b[i][j];
                }
                if(!visited[next_pos]){
                    visited[next_pos] = true;
                    q.push({next_pos,moves+1});
                }
            }
        }
        return -1;
    }
};