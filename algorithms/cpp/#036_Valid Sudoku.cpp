class Solution {
public:
    bool isValidRow(vector<vector<char>>& board, int r){
        bool dict[9];
        for(int i=0; i<9; i++) dict[i] = false;
        for(int i=0; i<9; i++){
            char ch = board[r][i];
            if (ch!='.') {
                int index = ch-'1';
                if(dict[index]==true) return false;
                else dict[index] = true;
            }
        }
        return true;
    }
    
    bool isValidColumn(vector<vector<char>>& board, int c){
        bool dict[9];
        for(int i=0; i<9; i++) dict[i] = false;
        for(int i=0; i<9; i++){
            char ch = board[i][c];
            if (ch!='.') {
                int index = ch-'1';
                if(dict[index]==true) return false;
                else dict[index] = true;
            }
        }
        return true;
    }
    
    bool isValidBlock(vector<vector<char>>& board, int r, int c){
        bool dict[9];
        for(int i=0; i<9; i++) dict[i] = false;
        
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                char ch = board[r*3+i][c*3+j];
                if (ch!='.') {
                    int index = ch-'1';
                    if(dict[index]==true) return false;
                    else dict[index] = true;
                }
            }
        }
        
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0; i<9; i++) {
            if(!isValidRow(board, i)) return false;
            if(!isValidColumn(board, i)) return false;
            if(!isValidBlock(board, i/3, i%3)) return false;
        }
        
        return true;
    }
};
