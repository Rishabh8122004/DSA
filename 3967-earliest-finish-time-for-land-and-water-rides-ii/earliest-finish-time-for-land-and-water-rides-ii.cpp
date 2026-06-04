class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int l = INT_MAX,w = l,minl = l,minw = l;
        for(int i = 0;i<ls.size();i++){
            l = min(ls[i]+ld[i],l);
        }

        for(int i = 0;i<ws.size();i++){
            w = min(w,ws[i]+wd[i]);

            minl = min(minl, max(l,ws[i])+wd[i]);
        }

        for(int i = 0;i<ls.size();i++){
            minw = min(minw,max(w,ls[i])+ld[i]);
        }
        return min(minw,minl);
    }
};