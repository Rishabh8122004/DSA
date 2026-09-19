class Solution {
public:
    bool checkOverlap(int r, int cx, int cy, int x1, int y1, int x2, int y2) {

        // closest point to the centre

        int x = max(x1,min(cx,x2));
        int y = max(y1,min(cy,y2));

        return (((cx-x)*(cx-x) + (cy-y)*(cy-y)) <= r*r);
    }
};