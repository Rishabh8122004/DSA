class Solution {
public:
    bool squareIsWhite(string c) {
        int a = c[0]-'a';
        int b = c[1]-'1';
        return (a%2) != (b%2);
    }
};