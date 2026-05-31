class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        sort(ast.begin(),ast.end());
        for(int i = 0;i<ast.size();i++){
            if(mass>=ast.back())return true;
            if(mass<ast[i])return false;
            else mass += ast[i];
        }
        return true;
    }
};