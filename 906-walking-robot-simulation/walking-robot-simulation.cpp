class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // 4,-1,4,-2,4
        char D = 'N'; // starting direction
        int x = 0, y = 0;// starting point
        bool check = true; // checking if current point is obstacle or not
        int ans = 0;
        sort(obstacles.begin(),obstacles.end());
        for(int i = 0;i<commands.size();i++)
        {
            check = true;
            // TURNING RIGHT
            if( commands[i] == -1){
                if(D == 'N'){ D = 'E'; }
                else if(D == 'S'){ D = 'W'; }
                else if(D == 'E'){ D = 'S'; }
                else if(D == 'W'){ D = 'N'; }
            }
            // TURNING LEFT
            else if( commands[i] == -2){
                if(D == 'N'){ D = 'W'; }
                    else if(D == 'S'){ D = 'E'; }
                    else if(D == 'E'){ D = 'N'; }
                    else if(D == 'W'){ D = 'S'; }
            }
            else
            {
            for(int j = 1;j<=commands[i];j++)
            {   
                if(D == 'N'){ y++; }
                else if(D == 'S'){ y--; }
                else if(D == 'E'){ x++; }
                else if(D == 'W'){ x--; }
                if(check)
                {
                    int lo = 0,hi = obstacles.size()-1;
                while(lo<=hi)
                {
                    int mid = lo+(hi-lo)/2;
                    if(x == obstacles[mid][0] && y == obstacles[mid][1]){
                    if(D == 'N'){ y--; }
                    else if(D == 'S'){ y++; }
                    else if(D == 'E'){ x--; }
                    else if(D == 'W'){ x++; }
                    check = false;break;}
                    else if( x<obstacles[mid][0] ||( x == obstacles[mid][0] && y < obstacles[mid][1]) ){hi = mid-1;}
                    else if( x>obstacles[mid][0] || ( x == obstacles[mid][0] && y > obstacles[mid][1])  ){lo = mid+1;}
                }
                }
                if(check == false){
                    break;
                    }
                    int tempans = (x*x)+(y*y);
                    if(tempans >= ans){ans = tempans;}
            }
            }
        }
        return ans;
    }
};