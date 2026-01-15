class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v) {
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        int lenx = 0;
        int leny = 0;
        int curr = 0;
        for(int i = 0;i<h.size();i++){
            if(i<h.size()-1 && h[i] == h[i+1]-1){
                curr+=1;
                lenx = max(lenx,curr);
            }
            else curr = 0;
        }
        curr = 0;
        for(int i = 0;i<v.size();i++){
            if(i<v.size()-1 && v[i] == v[i+1]-1){
                curr+=1;
                leny = max(leny,curr);
            }
            else curr = 0;
        }
        int side = min(lenx+2,leny+2);
        return side*side;
    }
};