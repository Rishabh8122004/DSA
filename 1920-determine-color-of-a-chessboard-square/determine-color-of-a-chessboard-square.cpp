class Solution {
public:
    bool squareIsWhite(string c) {
        return ((c[0]-'a')%2) != ((c[1]-'1')%2);
    }
};