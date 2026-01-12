class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& p) {
        int n = p.size();
        int ans = 0;
        int x1,x2,y1,y2,a;
        for(int i = 0;i<n-1;i++){
            x1 = p[i][0];x2 = p[i+1][0];
            y1 = p[i][1];y2 = p[i+1][1];
            while((x1 != x2) || (y1 != y2)){
                if(x1<x2){
                    if(y1<y2){
                        a = min(x2-x1,y2-y1);
                        ans += a;
                        x1+=a;
                        y1+=a;
                    }
                    else if(y1 == y2){
                        a = x2-x1;
                        ans += a;
                        x1 += a;
                    }
                    else if(y1 > y2){
                        a = min(x2-x1,y1-y2);
                        ans += a;
                        x1+=a;
                        y1-=a;
                    }
                }
                else if(x1 == x2){
                    ans += abs(y1-y2);
                    y1 = y2;
                }
                else if(x1 > x2){
                    if(y1 > y2){
                        a = min(x1-x2,y1-y2);
                        ans += a;
                        x1-=a;
                        y1-=a;
                    }
                    else if(y1 == y2){
                        ans += abs(x1-x2);
                        x1 = x2;
                    }
                    else if(y1 < y2){
                        a = min(x1-x2,y2-y1);
                        ans += a;
                        x1 -= a;
                        y1 += a;
                    }
                }
            }
        }
        return ans;
    }
};