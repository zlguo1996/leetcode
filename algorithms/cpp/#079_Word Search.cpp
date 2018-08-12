class Solution {
public:
    bool mark(vector<vector<char>>& board, pair<int, int> pos){
        if(board[pos.first][pos.second]==',') return false;
        board[pos.first][pos.second]=',';
        return true;
    }
    void unmark(vector<vector<char>>& board, pair<int, int> pos, char c){
        board[pos.first][pos.second]=c;
    }
    bool available(vector<vector<char>>& board, pair<int, int> pos){
        int rs=board.size(), cs=board[0].size();
        if(pos.first>=rs||pos.first<0||pos.second>=cs||pos.second<0) return false;
        return true;
    }
    bool dfs(vector<vector<char>>& board, pair<int, int> pos, int p, string& word){
        if(p==word.size()-1) return true;
        int next_pos_vec[8] = {-1,0,0,-1,1,0,0,1};
        for (int i=0; i<4; i++) {
            pair<int, int> next_pos(pos.first+next_pos_vec[i*2], pos.second+next_pos_vec[i*2+1]);
            if(available(board, next_pos)&&board[next_pos.first][next_pos.second]==word[p+1]){
                if(mark(board, next_pos)&&dfs(board, next_pos, p+1, word)) return true;
                unmark(board, next_pos, word[p+1]);
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size()==0) return true;
        if(board.size()==0||board[0].size()==0) return false;
        
        vector<pair<int, int>> start_pos;
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                pair<int, int> pos(i, j);
                if(word[0]==board[i][j]) start_pos.push_back(pos);
            }
        }
        
        for(auto pos:start_pos){
            mark(board, pos);
            if(dfs(board, pos, 0, word)) return true;
            unmark(board, pos, word[0]);
        }
        return false;
    }
};
