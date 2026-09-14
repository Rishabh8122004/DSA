class Solution {
public:
    bool isRectangleOverlap(vector<int>& r1, vector<int>& r2) {
        if((r1[2] <= r2[0]) || (r2[2] <= r1[0])){ // x2 is away or shorter , cant overlap
            return false;
        }
        if((r1[3] <= r2[1]) || (r2[3] <= r1[1])){ // y2 is shorter , cant overlap
            return false;
        }
        return true;
    }
};