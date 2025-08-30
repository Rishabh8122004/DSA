class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0;i<9;i++){
            vector<bool> v(9,true);
            for(int j = 0;j<9;j++){
                if(board[i][j] == '.') continue;
                if(v[board[i][j]-49] == true) v[board[i][j]-49] = false;
                else return false;
            }
        }
        for(int i = 0;i<9;i++){
            vector<bool> v(9,true);
            for(int j = 0;j<9;j++){
                if(board[j][i] == '.') continue;
                if(v[board[j][i]-49] == true) v[board[j][i]-49] = false;
                else return false;
            }
        }
        int a = 0;//row
        while(a<=6){
            int b = 0;//columns
            while(b<=6){
                vector<bool> v(9,true);
                for(int i = 0;i<3;i++){
                    for(int j = 0;j<3;j++){
                        if(board[i+a][j+b] == '.') continue;
                        if(v[board[i+a][j+b]-49] == true) v[board[i+a][j+b]-49] = false;
                        else return false;
                    }
                }
                b+=3;
            }
            a+=3;
        }
        return true;
    }
};